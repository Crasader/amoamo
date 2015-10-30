#include "amoamo/common/node/Util.h"
#include "amoamo/common/node/ui/EditBox.h"
#include "cocostudio/CocoStudio.h"
#include "ui/cocosGUI.h"
#include <typeinfo>
#include <future>

USING_NS_CC;

namespace amoamo {
namespace common {
namespace node {
    
    void Util::replaceByEditBox(cocos2d::Node* targetNode, const char* nodeName, const char* replaceName, const std::string& placeholderText, const std::string& initialText, std::function<void(cocos2d::extension::EditBox* editBox, const std::string& string)> onChange) {
        auto node = targetNode->getChildByName(nodeName);
        if (nullptr == node) {
            CCLOG("textfield node (name:%s) not found.", nodeName);
            return;
        }
        auto textfield = static_cast<cocos2d::ui::TextField*>(node);
        amoamo::common::node::ui::EditBox* editBox = static_cast<amoamo::common::node::ui::EditBox*>(amoamo::common::node::ui::EditBox::create(textfield->getContentSize(), cocos2d::ui::Scale9Sprite::create("dummy.png")));
        
        // EditBoxのイベント
        auto editBoxDelegate = new amoamo::common::node::ui::EditBoxDelegate();
        editBoxDelegate->setEventOnChange(onChange);
        editBox->setDelegate(editBoxDelegate);
        
        editBox->setFont("PixelMplus12-Regular.ttf", 40.0f);
        editBox->setPlaceHolder(placeholderText.c_str());
        editBox->setPlaceholderFont("PixelMplus12-Regular.ttf", 40.0f);
        editBox->setPlaceholderFontColor(Color3B::BLACK);
        editBox->setFontColor(Color3B::BLACK);
        editBox->setMaxLength(12);
        editBox->setText(initialText.c_str());
        editBox->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
        editBox->setInputMode(cocos2d::ui::EditBox::InputMode::ANY);
        editBox->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
        auto pos = textfield->getPosition();
        editBox->setPosition(pos);
        log("%f, %f", pos.x, pos.y);
        targetNode->removeChildByName(nodeName);
        targetNode->addChild(editBox, 0, replaceName);
        
        /*
         // フォーカス状態にする
         if (0 == initialText.length()) {
         editBox->touchDownAction(NULL, cocos2d::ui::Widget::TouchEventType::ENDED);
         }
         */
    }
        
    void Util::replaceByEditBox(cocos2d::Node* targetNode, const char* nodeName, const char* replaceName, const std::string& placeholderText, const std::string& initialText) {
        replaceByEditBox(targetNode, nodeName, replaceName, placeholderText, initialText, [](cocos2d::extension::EditBox* editBox, const std::string& string){});
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
    
    void Util::replaceLabelText(cocos2d::Node* targetNode, const char* labelName, const char* text) {
        auto node = targetNode->getChildByName(labelName);
        if (nullptr == node) {
            CCLOG("label node (name:%s) not found.", labelName);
            return;
        }
        auto textNode = static_cast<cocos2d::ui::Text*>(node);
        CCLOG("label node (name:%s) set to %s", labelName, text);
        textNode->setString(text);
    }
    
    void Util::replaceTextNodeToLabel(cocos2d::Node* targetNode, const char* textNodeName)
    {
        auto textNode = targetNode->getChildByName<cocos2d::ui::Text*>(textNodeName);
        if (nullptr == textNode) {
            CCLOG("text node (name:%s) not found.", textNodeName);
            return;
        }
        auto label = Label::createWithTTF(textNode->getString(), textNode->getFontName(), textNode->getFontSize());
        label->setPosition(textNode->getPosition());
        label->setAnchorPoint(textNode->getAnchorPoint());
        label->setColor(textNode->getColor());
        textNode->removeFromParent();
        targetNode->addChild(label);
        
    }
    
    Node* Util::loadFromCSThreadSafe(const char* resourceName) {
        std::promise<Node*> p;
        std::future<Node*> f = p.get_future();
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([&]() {
            log("performFunctionInCocosThread");
            CSLoader::getInstance()->setRecordJsonPath(true);
            auto node = CSLoader::getInstance()->createNode(resourceName);
            p.set_value(node);
            log("performFunctionInCocosThread end");
        });
        log("f.get()");
        auto node = f.get();
        log("f.get() done");
        node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        return node;
    }
    
    Node* Util::loadFromCS(const char* resourceName) {
        CSLoader::getInstance()->setRecordJsonPath(true);
        auto node = CSLoader::getInstance()->createNode(resourceName);
        node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        return node;
    }
    
    
    void Util::addRecursiveGlobalZOrder(cocos2d::Node* targetNode, int zOrder) {
        for (auto node : targetNode->getChildren()) {
            /*
            auto sprite = dynamic_cast<cocos2d::Sprite*>(node);
            if (nullptr != sprite) {
                sprite->setGlobalZOrder(zOrder + sprite->getLocalZOrder());
            }
             */
            node->setGlobalZOrder(zOrder + node->getLocalZOrder());
            addRecursiveGlobalZOrder(node, zOrder);
        }
    }
    
    void Util::setRecursiveAliasTexParameters(cocos2d::Node* targetNode) {
        for (auto node : targetNode->getChildren()) {
            auto sprite = dynamic_cast<cocos2d::Sprite*>(node);
            if (nullptr != sprite) {
                sprite->getTexture()->setAliasTexParameters();
            }
            setRecursiveAliasTexParameters(node);
        }
    }
    
}// namespace node
}// namespace common
}// namespace amoamo