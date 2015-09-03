#include "RangeSpriteScroller.h"

namespace amoamo {
namespace common {
namespace node {
    
    RangeSpriteScroller::RangeSpriteScroller(Rect rect):enableRewindX(true),enableRewindY(true) {
        this->rect = rect;
    }
    
    void RangeSpriteScroller::setEnableRewindX(bool boolean) {
        this->enableRewindX = boolean;
    }
    
    void RangeSpriteScroller::setEnableRewindY(bool boolean) {
        this->enableRewindY = boolean;
    }
    
    void RangeSpriteScroller::scroll(const Vec2 &factor) {
        auto it = sprites.begin();
        while(it != sprites.end()) {
            auto sprite = it->first;
            auto vector = it->second;
            float moveX = vector.x * factor.x;
            float moveY = vector.y * factor.y;
            auto newPosition = sprite->getPosition() + Vec2(moveX, moveY);
            
            if (this->enableRewindX) {
                if (newPosition.x < rect.getMinX()) {
                    newPosition.x = newPosition.x + rect.size.width;
                } else if (rect.getMaxX() < newPosition.x) {
                    newPosition.x = newPosition.x + -rect.size.width;
                }
            }
            if (this->enableRewindY) {
                if (newPosition.y < rect.getMinY()) {
                    newPosition.y = newPosition.y + rect.size.height;
                } else if (rect.getMaxY() < newPosition.y) {
                    newPosition.y = newPosition.y + -rect.size.height;
                }
            }
            sprite->setPosition(newPosition);
            
            ++it;
        }
    }

}// namespace node
}// namespace common
}// namespace amoamo
