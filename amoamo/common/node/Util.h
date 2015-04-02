#ifndef AMOAMO_COMMON_NODE_UTIL_H
#define AMOAMO_COMMON_NODE_UTIL_H

#include <iostream>

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

namespace amoamo {
namespace common {
namespace node {
    
class Util
{
public:
    // EditBox
    static void replaceByEditBox(cocos2d::Node* targetNode, const char* nodeName, const char* replaceName, const std::string& placeholderText, const std::string& initialText);
    
    // Button
    static void setCallBackToButton(cocos2d::Node* targetNode, const char* buttonName, const cocos2d::ui::Widget::ccWidgetTouchCallback &callback);
    static void setCallBackToButton(cocos2d::Node* targetNode, const char* buttonName, const std::function<void()> &callback);
    
    // Label
    static void setLabelText(cocos2d::Node* targetNode, const char* labelName, const char* text);
    
    // CS
    static Node* loadFromCS(const char* resourceName);
};

}// namespace node
}// namespace common
}// namespace amoamo

#endif /* defined(AMOAMO_COMMON_NODE_UTIL_H) */
