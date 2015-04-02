#include "amoamo/common/node/Util.h"
#include "cocostudio/CocoStudio.h"
#include "cocosGUI.h"
#include <typeinfo>

USING_NS_CC;

namespace amoamo {
namespace common {
namespace node {
        
    void Util::replaceByEditBox(cocos2d::Node* targetNode, const char* nodeName, const char* replaceName, const std::string& placeholderText, const std::string& initialText) {
        auto node = targetNode->getChildByName(nodeName);
        if (nullptr == node) {
            CCLOG("textfield node (name:%s) not found.", nodeName);
            return;
        }
        auto textfield = static_cast<cocos2d::ui::TextField*>(node);
        auto editBox = cocos2d::ui::EditBox::create(textfield->getContentSize(), cocos2d::ui::Scale9Sprite::create("dummy.png"));

        editBox->setFont("PixelMplus12-Regular.ttf", 40.0f);
        editBox->setPlaceHolder(placeholderText.c_str());
        editBox->setPlaceholderFont("PixelMplus12-Regular.ttf", 40.0f);
        editBox->setPlaceholderFontColor(Color3B::BLACK);
        editBox->setFontColor(Color3B::BLACK);
        editBox->setMaxLength(12);
        editBox->setText(initialText.c_str());
        editBox->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
        editBox->setInputMode(cocos2d::ui::EditBox::InputMode::ANY);
        editBox->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        auto pos = textfield->getPosition();
        /*
         // フォーカス状態にする
        if (0 == initialText.length()) {
            editBox->touchDownAction(NULL, cocos2d::ui::Widget::TouchEventType::ENDED);
        }
        */
        editBox->setPosition(pos);
        targetNode->removeChildByName("textfield");
        targetNode->addChild(editBox, 0, replaceName);
    }
    
    void Util::setCallBackToButton(cocos2d::Node* targetNode, const char* buttonName, const cocos2d::ui::Widget::ccWidgetTouchCallback &callback) {
        auto btnNode = targetNode->getChildByName(buttonName);
        if (nullptr == btnNode) {
            CCLOG("button node (name:%s) not found.", buttonName);
            return;
        }
        auto button = static_cast<cocos2d::ui::Button*>(btnNode);
        button->addTouchEventListener(callback);
    }
    
    void Util::setCallBackToButton(cocos2d::Node* targetNode, const char* buttonName, const std::function<void()> &callback) {
        setCallBackToButton(targetNode, buttonName, [=](Ref*, cocos2d::ui::Widget::TouchEventType type){
            if (type != cocos2d::ui::Widget::TouchEventType::ENDED) {return;}
            callback();
        });
    }
    
    void Util::setLabelText(cocos2d::Node* targetNode, const char* labelName, const char* text) {
        auto node = targetNode->getChildByName(labelName);
        if (nullptr == node) {
            CCLOG("label node (name:%s) not found.", labelName);
            return;
        }
        auto textNode = static_cast<cocos2d::ui::Text*>(node);
        textNode->setString(text);
    }
    
    Node* Util::loadFromCS(const char* resourceName) {
        CSLoader::getInstance()->setRecordJsonPath(true);
        auto node = CSLoader::getInstance()->createNode(resourceName);
        node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        return node;
    }
    
}// namespace node
}// namespace common
}// namespace amoamo