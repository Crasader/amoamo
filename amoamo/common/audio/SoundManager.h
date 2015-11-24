#pragma once

#include "cocos2d.h"

#include "BGMManager.h"
#include "SEManager.h"

namespace amoamo {
namespace common {
namespace audio {

class SoundManager
{
private:
    SoundManager();
    ~SoundManager();
    
public:
    static SoundManager* create();
    void destroy();
    
    static SoundManager* getInstance() { return s_manager; }
    
private:
    bool init();
    
public:
    void pause();
    void resume();
    
    BGMManager* getBGMManager() { return _bgmManager; }
    SEManager* getSEManager() { return _seManager; }
    
private:
    static SoundManager* s_manager;
    
    BGMManager* _bgmManager;
    SEManager* _seManager;
};

}// namespace audio
}// namespace common
}// namespace amoamo

#define SOUND_MANAGER()	(amoamo::common::audio::SoundManager::getInstance())
#define BGM_MANAGER()	(amoamo::common::audio::SoundManager::getInstance()->getBGMManager())
#define SE_MANAGER()	(amoamo::common::audio::SoundManager::getInstance()->getSEManager())