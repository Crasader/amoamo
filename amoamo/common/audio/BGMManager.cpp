#include "cocos2d.h"
#include "SoundManager.h"
#include "BGMManager.h"
#include "audio/include/AudioEngine.h"


using namespace cocos2d::experimental;
using namespace std;

namespace amoamo {
namespace common {
namespace audio {

const float BGMObject::_fadeTime = 2.0f;

BGMObject::BGMObject()
: _audioId(AudioEngine::INVALID_AUDIO_ID)
, _bgmId(0)
, _state(INIT)
{
    _scheduler = Director::getInstance()->getScheduler();
    _scheduler->retain();
    _running = true;
}

BGMObject::~BGMObject()
{
    _scheduler->unscheduleUpdate(this);
    CC_SAFE_RELEASE_NULL(_scheduler);
}

BGMObject* BGMObject::create(int32_t bgmId, bool fadeIn)
{
    BGMObject* object = new BGMObject();
    //log("create bgmId:%d fadeIn:%s", bgmId, fadeIn ? "true" : "false");
    if (object && object->init(bgmId, fadeIn)) {
        //object->autorelease();
    } else if (object) {
        delete object;
        object = nullptr;
    }
    return object;
}

void BGMObject::release()
{
    delete this;
}

bool BGMObject::init(int32_t bgmId, bool fadeIn)
{
    _bgmId = bgmId;
    //log("init bgmId:%d fadeIn:%s", bgmId, fadeIn ? "true" : "false");
    
    auto bgmManager = BGM_MANAGER();
    _audioId = AudioEngine::play2d(bgmManager->getBGMList()[_bgmId], true, bgmManager->getVolume());
    if (_audioId == AudioEngine::INVALID_AUDIO_ID) {
        return false;
    }
    
    if (fadeIn) {
        _timer = 0.0f;
        AudioEngine::setVolume(_audioId, 0.0f);
        _state = FADE_IN;
    } else {
        _state = PLAYING;
    }
    
    _scheduler->scheduleUpdate(this, 0, !_running);
    
    return true;
}

void BGMObject::update(float delta)
{
    if (_audioId == AudioEngine::INVALID_AUDIO_ID) {
        // INVALIDのまま存在はしないはずだが…
        CC_SAFE_RELEASE(this);
        return;
    }
    
    _timer += delta;
    
    if (_state == FADE_IN) {
        if (_timer >= _fadeTime) {
            _timer = _fadeTime;
            _state = PLAYING;
        }
        
        AudioEngine::setVolume(_audioId, SoundManager::getInstance()->getBGMManager()->getVolume() * (_timer / _fadeTime));
    } else if (_state == FADE_OUT) {
        if (_timer >= _fadeTime) {
            _timer = _fadeTime;
            //log("_state == FADE_OUT bgmId:%d", _bgmId);
            _state = END;
            stop(false);
            //delete this;
        } else {
            AudioEngine::setVolume(_audioId, SoundManager::getInstance()->getBGMManager()->getVolume() * ((_fadeTime - _timer) / _fadeTime));
        }
    } else {
        // 再生中(なにもしない)
    }
}

void BGMObject::stop(bool fadeOut)
{
    if (_audioId != AudioEngine::INVALID_AUDIO_ID) {
        if (!fadeOut) {
            AudioEngine::stop(_audioId);
            //log("AudioEngine::stop timer:%f, seID:%d", _timer, _bgmId);
            CC_SAFE_RELEASE(this);
        } else {
            //log("AudioEngine::start fadeOut timer:%f, seID:%d", _timer, _bgmId);
            _state = FADE_OUT;
            _timer = 0.0f;
        }
    }
    
}

void BGMObject::pause()
{
    if (_audioId != AudioEngine::INVALID_AUDIO_ID) {
        AudioEngine::pause(_audioId);
    }
    _running = false;
}

void BGMObject::resume()
{
    if (_audioId != AudioEngine::INVALID_AUDIO_ID) {
        AudioEngine::resume(_audioId);
    }
    _running = true;
}

void BGMObject::setVolume(float vol)
{
    if (_audioId != AudioEngine::INVALID_AUDIO_ID) {
        AudioEngine::setVolume(_audioId, vol);
    }
}


BGMManager::BGMManager()
: _object(NULL)
, _volume(1.0f)
{
}
BGMManager::~BGMManager()
{
}

BGMManager* BGMManager::create()
{
    BGMManager* manager = new BGMManager();
    
    if (manager && manager->init()) {
        return manager;
    }
    else {
        if (manager) { delete manager; }
        return NULL;
    }
}

void BGMManager::destroy()
{
    delete this;
}

bool BGMManager::init()
{
    return true;
}

void BGMManager::play(int32_t bgmId, bool isCrossFade)
{
    //log("BGMManager::play bgmId:%d", bgmId);
    if (_object == nullptr) {
        _object = BGMObject::create(bgmId, false);
    } else {
        //log("AudioEngine::stop on Crossfade: %s", isCrossFade ? "true": "false");
        _object->stop(isCrossFade);
        _object = BGMObject::create(bgmId, isCrossFade);
    }
}

void BGMManager::stop(bool fade)
{
    if (_object) {
        _object->stop(fade);
        _object = NULL;
    }
}

void BGMManager::pause()
{
    if (_object) {
        _object->pause();
    }
}

void BGMManager::resume()
{
    if (_object) {
        _object->resume();
    }
}

void BGMManager::setVolume(float volume)
{
    _volume = volume;
    if (_object) {
        _object->setVolume(volume);
    }
}


}// namespace audio
}// namespace common
}// namespace amoamo