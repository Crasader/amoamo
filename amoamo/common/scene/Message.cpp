#include "amoamo/common/scene/Message.h"

#include "cocostudio/CocoStudio.h"
#include "cocosGUI.h"

USING_NS_CC;
using namespace ui;

namespace amoamo {
namespace common {
namespace scene {

    cocos2d::Scene* Message::createDialogOk(const char* message, const std::function<void()> &callback)
    {
        auto scene = cocos2d::Scene::create();
        
        //scene->addChild(MaskLayer::create());
        
        CSLoader::getInstance()->setRecordJsonPath(true);
        auto node = CSLoader::getInstance()->createNode("res/DialogOk.csb");
        node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        node->setPosition(Vec2(scene->getBoundingBox().getMidX(), scene->getBoundingBox().getMidY()));

        auto button_ok = static_cast<cocos2d::ui::Button*>(node->getChildByName("button_ok"));
        button_ok->addTouchEventListener([=](Ref* ref, Widget::TouchEventType type){
            if (type != Widget::TouchEventType::ENDED) {return;}
            callback();
        });
        
        scene->addChild(node);
        
        return scene;
    }
    
}// namespace scene
}// namespace common
}// namespace amoamo