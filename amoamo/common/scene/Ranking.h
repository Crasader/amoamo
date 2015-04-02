#ifndef __TestProject34__Ranking__
#define __TestProject34__Ranking__

#include <iostream>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

namespace amoamo {
namespace common {
namespace scene {
    
    class Ranking
    {
    public:
        static cocos2d::Scene* createNameInput(
               const std::function<void(std::string)> &callbackOk,
               const std::function<void()> &callbackCancel
        );
    };
    
}// namespace scene
}// namespace common
}// namespace amoamo

#endif /* defined(__TestProject34__Ranking__) */
