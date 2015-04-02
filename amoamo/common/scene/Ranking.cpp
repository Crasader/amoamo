#include "Ranking.h"
#include "amoamo/common/layer/InputLayer.h"

namespace amoamo {
namespace common {
namespace scene {
        
    USING_NS_CC;
    using namespace ui;
    using namespace amoamo::common;
    
    cocos2d::Scene* Ranking::createNameInput(
             const std::function<void(std::string)> &callbackOk,
             const std::function<void()> &callbackCancel
        )
    {
        auto scene = Scene::create();
        
        auto layer = layer::InputLayer::create();
        layer->replaceEditBox("placeholder", "initial");
        layer->setCallbackCancel([=](Ref* ref, Widget::TouchEventType type){
            if (type != Widget::TouchEventType::ENDED) {return;}
            callbackCancel();
        });
        layer->setCallbackOk([=](Ref* ref, Widget::TouchEventType type){
            if (type != Widget::TouchEventType::ENDED) {return;}
            callbackOk(layer->getInputText());
        });
        scene->addChild(layer);
        
        return scene;
    }
    
}// namespace scene
}// namespace common
}// namespace amoamo
