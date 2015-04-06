#include "amoamo/common/layer/Overlay.h"
#include "amoamo/common/node/Dialog.h"
#include "amoamo/common/node/Util.h"

using namespace amoamo::common;

namespace amoamo {
namespace common {
namespace layer {

    Layer* Overlay::createDialogOk(const char* contentText) {
        auto baseLayer = createUntouchableOverlayLayer();
        
        auto nodeDialog = node::Dialog::createDialogOk(Vec2(
            baseLayer->getBoundingBox().getMidX(),
            baseLayer->getBoundingBox().getMidY()
        ));
        
        node::Util::setLabelText(nodeDialog, "label_contents", contentText);
        node::Util::setLabelText(nodeDialog, "label_title", "たいとるだよ");
        node::Util::setCallBackToButton(nodeDialog, "button_ok", [=]{
            baseLayer->removeFromParent();
        });
        
        baseLayer->addChild(nodeDialog);
        
        return baseLayer;
    }
    
    Layer* Overlay::createOnNodeMiddle(Node* node) {
        auto baseLayer = createUntouchableOverlayLayer();
        
        node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        node->setPosition(Vec2(
                               baseLayer->getBoundingBox().getMidX(),
                               baseLayer->getBoundingBox().getMidY()
                               ));
        
        baseLayer->addChild(node);
        return baseLayer;
    }
    
    LayerColor* Overlay::createUntouchableOverlayLayer(int alpha) {
        auto layer = LayerColor::create(Color4B(0, 0, 0, alpha));
        
        // 半透明部分をタッチ不可能にするためのリスナー
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = [](Touch *touch, Event *event)->bool{
            // このイベントは登録しないとエラーが出る
            return true;
        };
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);
        
        return layer;
    }
    
}// namespace layer
}// namespace common
}// namespace amoamo