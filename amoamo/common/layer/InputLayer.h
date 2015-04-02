#ifndef __AndroidGame__InputLayer__
#define __AndroidGame__InputLayer__

#include <iostream>

#include "cocostudio/CocoStudio.h"
USING_NS_CC;

namespace amoamo {
namespace common {
namespace layer {

    class InputLayer : public Layer
    {
    public:
        CREATE_FUNC(InputLayer);
        /**
         * @fn
         * TextField を EditBox に置き換える
         * @return
         */
        void replaceEditBox(const char* placeholder, const char* initialText);
        void setCallbackOk(const cocos2d::ui::Widget::ccWidgetTouchCallback &callback);
        void setCallbackCancel(const cocos2d::ui::Widget::ccWidgetTouchCallback &callback);
        std::string const getInputText();
    private:
        static const char* NAME_NODE_EDITBOX;
        Node* input;

        virtual bool init();
    };
    
}// namespace layer
}// namespace common
}// namespace amoamo

#endif /* defined(__AndroidGame__InputLayer__) */
