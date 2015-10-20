#pragma once

#include "cocos2d.h"
#include "amoamo/common/node/SpriteScroller.h"
#include <utility>

USING_NS_CC;

namespace amoamo {
namespace common {
namespace node {
    
    class RangeSpriteScroller : public SpriteScroller
    {
    private:
        Rect rect;
        bool enableRewindX;
        bool enableRewindY;
    public:
        void scroll(const Vec2 &factor) override;
        /**
         * スクロール範囲は動的に定めたいので初期値で決めるようにしたくない
         */
        RangeSpriteScroller();
        
        void setScrollRange(const Rect rect);
        
        void setEnableRewindX(bool boolean);
        void setEnableRewindY(bool boolean);
    };
    
}// namespace node
}// namespace common
}// namespace amoamo