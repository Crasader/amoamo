#ifndef AMOAMO_COMMON_NODE_DIALOG_H
#define AMOAMO_COMMON_NODE_DIALOG_H

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;
using namespace ui;

namespace amoamo {
namespace common {
namespace node {
        
class Dialog
{
public:
    static Node* createDialogOk(const Vec2 position);
    static Node* createDialogInput(const Vec2 position);
};
    
}// namespace node
}// namespace common
}// namespace amoamo

#endif /* defined(AMOAMO_COMMON_NODE_DIALOG_H) */
