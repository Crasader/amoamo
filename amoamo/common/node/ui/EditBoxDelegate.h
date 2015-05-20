#pragma once

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

namespace amoamo {
namespace common {
namespace node {
namespace ui {
    
class EditBoxDelegate: public cocos2d::extension::EditBoxDelegate
{
public:
    void setEventOnChange(std::function<void(cocos2d::extension::EditBox* editBox, const std::string& text)> onChange) {
        this->onChange = onChange;
    }
    
    virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);
private:
    std::function<void(cocos2d::extension::EditBox* editBox, const std::string& text)> onChange;
};
    
}}}}