#include "SoundManager.h"
#include "BGMManager.h"
#include "SEManager.h"


namespace amoamo {
namespace common {
namespace audio {

SoundManager* SoundManager::s_manager = NULL;


SoundManager::SoundManager()
: _bgmManager(NULL)
, _seManager(NULL)
{
}

SoundManager::~SoundManager()
{
}

SoundManager* SoundManager::create()
{
    if (s_manager) {
        return s_manager;
    }
    
    s_manager = new SoundManager();
    
    if (s_manager && s_manager->init()) {
        return s_manager;
    }
    
    CC_SAFE_DELETE(s_manager);
    return NULL;
}

void SoundManager::destroy()
{
    if (_bgmManager) { _bgmManager->destroy(); _bgmManager = NULL; }
    if (_seManager) { _seManager->destroy(); _seManager = NULL; }
    s_manager = NULL;
    delete this;
}

bool SoundManager::init()
{
    _bgmManager = BGMManager::create();
    _seManager = SEManager::create();
    return true;
}

void SoundManager::pause()
{
    if (_bgmManager) { _bgmManager->pause(); }
    if (_seManager) { _seManager->pause(); }
}

void SoundManager::resume()
{
    if (_bgmManager) { _bgmManager->resume(); }
    if (_seManager) { _seManager->resume(); }
}
    
}// namespace audio
}// namespace common
}// namespace amoamo
