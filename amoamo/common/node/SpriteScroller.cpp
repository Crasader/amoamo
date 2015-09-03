#include "amoamo/common/node/SpriteScroller.h"

using namespace std;

namespace amoamo {
namespace common {
namespace node {
    
    void SpriteScroller::add(Sprite* s, Vec2 vector) {
        sprites.push_back(make_pair(s, vector));
    }
    
    void SpriteScroller::scroll(const Vec2 &factor) {
        auto it = sprites.begin();
        while(it != sprites.end()) {
            auto sprite = it->first;
            auto vector = it->second;
            
            auto newPosition =
            sprite->getPosition() +
            Vec2(vector.x * factor.x, vector.y * factor.y);
            sprite->setPosition(newPosition);
            
            ++it;
        }
    }

}// namespace node
}// namespace common
}// namespace amoamo