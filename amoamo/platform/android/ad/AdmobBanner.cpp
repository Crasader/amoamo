#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_ANDROID

#include "amoamo/ad/AdmobBanner.h"
#include <jni.h>
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

namespace amoamo {

namespace ad {
namespace admobbanner {
namespace helper {

    const char* const CLASS_NAME = "amoamo/ad/AdmobBanner";

    void callStaticVoidMethod(const char* name)
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
            t.env->DeleteLocalRef(t.classID);
        }
    }
    
} /* helper */
    
    void AdmobBanner::init(string adUnitId) {
        // do nothing on android
    }

    void AdmobBanner::hideAd() {
        amoamo::ad::admobbanner::helper::callStaticVoidMethod("jni_hide");
    }

    void AdmobBanner::showAd() {
        amoamo::ad::admobbanner::helper::callStaticVoidMethod("jni_show");
    }

} /* admobbanner */
}/* amoamo */
}/* ad */

#endif /* AMOAMO_PLATFORM_IS_ANDROID */
