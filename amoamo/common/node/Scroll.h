#ifndef AMOAMO_COMMON_NODE_SCROLL_H
#define AMOAMO_COMMON_NODE_SCROLL_H

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;
using namespace ui;

namespace amoamo {
namespace common {
namespace node {    
            
class Scroll
{
public:
    static Node* createNode(Size size);
};
    
}// namespace node
}// namespace common
}// namespace amoamo

#endif /* defined(AMOAMO_COMMON_NODE_SCROLL_H) */
