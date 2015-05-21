#include "amoamo/definition.h"

#include "amoamo/Device.h"
#include <jni.h>
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

namespace amoamo {
    
    const char* const CLASS_NAME = "amoamo/device/Device";
    
    void Device::isConnectedInternet(const char* tweet) {
        JniMethodInfo minfo;
        CCAssert(JniHelper::getStaticMethodInfo(minfo, CLASS_NAME, "isConnected", "()Z"), "Function doesn't exist");
        return minfo.env->CallStaticBooleanMethod(minfo.classID, minfo.methodID);
    }

}/* namespace amoamo */
