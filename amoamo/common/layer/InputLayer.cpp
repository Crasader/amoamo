#include "cocostudio/CocoStudio.h"
#include "cocosGUI.h"
#include "amoamo/common/node/Util.h"
#include "amoamo/common/layer/InputLayer.h"

USING_NS_CC;
using namespace amoamo::common;

namespace amoamo {
namespace common {
namespace layer {

    const char *InputLayer::NAME_NODE_EDITBOX = "editbox";

    void InputLayer::replaceEditBox(const char* textPlaceholder, const char* textInitial) {
        node::Util::replaceByEditBox(this->input, "textfield", NAME_NODE_EDITBOX, textPlaceholder, textInitial);
    }

    void InputLayer::setCallbackOk(const cocos2d::ui::Widget::ccWidgetTouchCallback &callback) {
        node::Util::setCallBackToButton(this->input, "button_ok", callback);
    }

    void InputLayer::setCallbackCancel(const cocos2d::ui::Widget::ccWidgetTouchCallback &callback) {
        node::Util::setCallBackToButton(this->input, "button_cancel", callback);
        node::Util::setCallBackToButton(this->input, "button_close", callback);
    }

    std::string const InputLayer::getInputText() {
        auto node = this->input->getChildByName(NAME_NODE_EDITBOX);
        if (nullptr == node) {
            CCLOG("editbox not found");
            return std::string();
        }
        auto editBox = static_cast<cocos2d::ui::EditBox*>(node);
        return editBox->getText();
    }

    bool InputLayer::init(){
        if (!Layer::init()) {
            return false;
        }
        // load
        CSLoader::getInstance()->setRecordJsonPath(true);
        auto node = CSLoader::getInstance()->createNode("res/DialogInput.csb");
        node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        node->setPosition(Vec2(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY()));
        this->input = node;
        this->addChild(node);
        
        return true;
    }

}// namespace layer
}// namespace common
}// namespace amoamo