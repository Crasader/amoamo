#pragma once

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "amoamo/common/node/ui/EditBoxDelegate.h"
#include <memory>

namespace amoamo {
namespace common {
namespace node {
namespace ui {
    
    class EditBox: public cocos2d::ui::EditBox
    {
    public:
        virtual ~EditBox() {
            cocos2d::log("virtual ~EditBox");
            delete delegate;
        }
        amoamo::common::node::ui::EditBoxDelegate* getDelegate();
        void initializeDelegate() {
            //delegate = new amoamo::common::node::ui::EditBoxDelegate();
            //setDelegate(delegate);
        }
        void setEditBoxDelegate(amoamo::common::node::ui::EditBoxDelegate delegate);
    private:
        amoamo::common::node::ui::EditBoxDelegate* delegate;
    };

}}}}