#include "amoamo/common/node/ui/EditBox.h"

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
using namespace ui;


namespace amoamo {
namespace common {
namespace node {
namespace ui {
    
    amoamo::common::node::ui::EditBoxDelegate* EditBox::getDelegate() {
        return delegate;
    }
    
    /*
    void EditBox::setEditBoxDelegate(amoamo::common::node::ui::EditBoxDelegate delegate) {
        this->delegate = delegate;
        //this->setDelegate(&this->delegate);
    }*/

}}}}