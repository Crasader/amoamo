#pragma once

#include "cocos2d.h"

using namespace cocos2d;

namespace amoamo {
namespace common {
namespace audio {

class BGMObject
{
public:
    enum State {
        INIT = 0,
        FADE_OUT = 1,
        FADE_IN = 2,
        PLAYING = 3,
        END = 4,
    };
    
private:
    BGMObject();
    virtual ~BGMObject();

public:
    static BGMObject* create(int32_t bgmId, bool fadeIn);
    
private:
    bool init(int32_t bgmId, bool fadeIn);
    void release();
    
public:
    void update(float delta);
    
public:
    void stop(bool fadeOut);
    void pause();
    void resume();
    
    void setVolume(float volume);
    
private:
    static const float _fadeTime;
    
    Scheduler *_scheduler;          ///< scheduler used to schedule timers and updates
    bool _running;                  ///< is running
    
    State _state;
    int32_t _audioId;
    int32_t _bgmId;
    float _timer;
};


class BGMManager
{
CC_SYNTHESIZE(const std::string*, _bgmList, BGMList);
public:
    enum BGM_ID {
        BGM_TEST001 = 0,
        BGM_TEST002,
        
        BGM_MAX,
    };
    
private:
    BGMManager();
    ~BGMManager();
    
public:
    static BGMManager* create();
    void destroy();
    
private:
    bool init();
    
public:
    void play(int32_t bgmId, bool isCrossFade = false);
    void stop(bool fade);
    void pause();
    void resume();
    
    float getVolume() { return _volume; }
    void setVolume(float vol);
private:
    BGMObject* _object;
    float _volume;
};


}// namespace audio
}// namespace common
}// namespace amoamo