#ifndef __TestProject34__Overlay__
#define __TestProject34__Overlay__

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
private:
    static LayerColor* createUntouchableOverlayLayer(int alpha = 128);
};

}// namespace layer
}// namespace common
}// namespace amoamo

#endif /* defined(__TestProject34__OverlayDialog__) */
