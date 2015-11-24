#pragma once


namespace amoamo {
namespace common {
namespace audio {

class SEManager
{
private:
    SEManager();
    ~SEManager();
    
public:
    static SEManager* create();
    void destroy();
    
private:
    bool init();
    
public:
    int32_t play(uint32_t seId, bool loop);
    void stop(int32_t audioId);
    void pause(int32_t audioId);
    void pause();
    void resume(int32_t audioId);
    void resume();
    void preload(uint32_t seId);
    void setSEList(const std::string* list) {
        this->_seList = list;
    }
    
    float getVolume() { return _volume; }
    void setVolume(float volume);
    
private:
    float _volume;
    const std::string* _seList;
};

}// namespace audio
}// namespace common
}// namespace amoamo
