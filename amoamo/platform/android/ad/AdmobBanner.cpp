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
    
    void callStaticVoidMethodWithString(const char* name, const char* c_string)
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "(Ljava/lang/String;)V")) {
            jstring j_string = t.env->NewStringUTF(c_string);
            t.env->CallStaticVoidMethod(t.classID, t.methodID, j_string);
            t.env->DeleteLocalRef(t.classID);
            t.env->DeleteLocalRef(j_string);
        }
    }
    
    void callStaticVoidMethod(const char* name)
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "()V")) {
            t.env->CallStaticVoidMethod(t.classID, t.methodID);
            t.env->DeleteLocalRef(t.classID);
        }
    }
    
} /* helper */
} /* admobbanner */
    
    void AdmobBanner::init(const std::string adUnitId) {
        amoamo::ad::admobbanner::helper::callStaticVoidMethodWithString("jniInit", adUnitId.c_str());
    }

    void AdmobBanner::hideAd() {
        amoamo::ad::admobbanner::helper::callStaticVoidMethod("jniHide");
    }

    void AdmobBanner::showAd() {
        amoamo::ad::admobbanner::helper::callStaticVoidMethod("jniShow");
    }

}/* ad */
}/* amoamo */

#endif /* AMOAMO_PLATFORM_IS_ANDROID */
