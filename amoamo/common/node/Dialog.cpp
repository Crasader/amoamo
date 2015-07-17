#include "amoamo/common/node/Dialog.h"
#include "cocostudio/CocoStudio.h"
#include "ui/cocosGUI.h"
#include "Util.h"

namespace amoamo {
namespace common {
namespace node {

Node* Dialog::createDialogOk(const Vec2 position) {
    auto node = Util::loadFromCS("res/DialogOk.csb");
    node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    node->setPosition(position);
    return node;
}

Node* Dialog::createDialogInput(const Vec2 position) {
    auto node = Util::loadFromCS("res/DialogInput.csb");
    node->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    node->setPosition(position);
    return node;
}

}// namespace node
}// namespace common
}// namespace amoamo
