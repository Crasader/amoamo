#pragma once

#include <iostream>

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;

namespace amoamo {
namespace common {
namespace node {
    
class Util
{
public:
    // EditBox
    static void replaceByEditBox(cocos2d::Node* targetNode, const char* nodeName, const char* replaceName, const std::string& placeholderText, const std::string& initialText);
    static void replaceByEditBox(cocos2d::Node* targetNode, const char* nodeName, const char* replaceName, const std::string& placeholderText, const std::string& initialText, std::function<void(cocos2d::extension::EditBox* editBox, const std::string& string)> onChange);
    
    // Button
    static void setCallBackToButton(cocos2d::Node* targetNode, const char* buttonName, const cocos2d::ui::Widget::ccWidgetTouchCallback &callback);
    static void setCallBackToButton(cocos2d::Node* targetNode, const char* buttonName, const std::function<void()> &callback);
    
    // Label
    
    /**
     * TextNodeのstringを変更する
     */
    static void replaceTextString(cocos2d::Node* targetNode, const char* nameNodeText, const char* string);
    
    /**
     * TextNodeをLabelNodeに入れ替える(TextNodeは消える)
     */
    static void replaceTextNodeToLabel(cocos2d::Node* targetNode, const char* nodeName);
    
    
    /**
     * LabelNodeのstringを変更する
     */
    static void replaceLabelString(cocos2d::Node* targetNode, const char* nodeName, const char* string);
    
    // CS
    static Node* loadFromCSThreadSafe(const char* resourceName);
    static Node* loadFromCS(const char* resourceName);
    
    // recursive settings
    static void addRecursiveGlobalZOrder(cocos2d::Node* targetNode, int zOrder);
    static void setRecursiveAliasTexParameters(cocos2d::Node* targetNode);
};

}// namespace node
}// namespace common
}// namespace amoamo
