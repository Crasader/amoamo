#pragma once

#include <iostream>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

namespace amoamo {
namespace common {
namespace scene {
    
    class Message
    {
    public:
        static cocos2d::Scene* createDialogOk(const char* message, const std::function<void()> &callback);
    };
    
}// namespace scene
}// namespace common
}// namespace amoamo
