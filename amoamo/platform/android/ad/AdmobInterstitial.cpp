#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_ANDROID

#include "amoamo/ad/AdmobInterstitial"
#include <jni.h>
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

namespace amoamo {
namespace ad {

namespace admobinterstitial {
namespace helper {

    const char* const CLASS_NAME = "amoamo/ad/AdmobInterstitial";

    void callStaticVoidMethod(const char* name)
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
            t.env->DeleteLocalRef(t.classID);
        }
    }
    
} /* helper */
} /* admobinterstitial */
    
    void AdmobInterstitial::init(string adUnitId) {
        // do nothing on android
    }

    void AdmobInterstitial::showAd() {
        //amoamo::ad::admobinterstitial::helper::callStaticVoidMethod("jni_show");
    }
    
    void AdmobInterstitial::isReady() {
        //amoamo::ad::admobinterstitial::helper::callStaticVoidMethod("jni_hide");
    }

}/* ad */
}/* amoamo */

#endif /* AMOAMO_PLATFORM_IS_ANDROID */
