#pragma once

#include <iostream>

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

namespace amoamo {
namespace common {
namespace layer {

class Overlay
{
public:
    static Layer* createDialogOk(const char* contentText);
    
    /**
     * 例えばローディング画面をつくる時に使用される
     */
    static Layer* createOnNodeMiddle(Node* node);
    
    static LayerColor* createUntouchableOverlayLayer(int alpha = 128);
};

}// namespace layer
}// namespace common
}// namespace amoamo
