#include "amoamo/common/node/ui/EditBoxDelegate.h"

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;

namespace amoamo {
namespace common {
namespace node {
namespace ui {
    

// 入力開始時
void EditBoxDelegate::editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox) {
    log("editBoxEditingDidBegin");
}

// 入力フォーカスが外れた時
void EditBoxDelegate::editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox) {
    log("editBoxEditingDidEnd");
}

// 変更があった場合
void EditBoxDelegate::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text) {
    this->onChange(editBox, text);
}

// 入力中にEnter
void EditBoxDelegate::editBoxReturn(cocos2d::extension::EditBox* editBox) {
    log("editBoxReturn");
}

}}}}