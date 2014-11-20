#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_ANDROID

#include "amoamo/ad/AdmobInterstitial.h"
#include <jni.h>
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

namespace amoamo {
namespace ad {

namespace admobinterstitial {
namespace helper {

    const char* const CLASS_NAME = "amoamo/ad/AdmobInterstitial";
    
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
    
    bool callStaticBoolMethod(const char* name)
    {
        cocos2d::JniMethodInfo t;
        if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "()Z")) {
            bool result = (t.env->CallStaticBooleanMethod(t.classID, t.methodID) == JNI_TRUE);
            t.env->DeleteLocalRef(t.classID);
            return result;
        } else {
            return false;
        }
    }
    
} /* helper */
} /* admobinterstitial */
    
    void AdmobInterstitial::init(const std::string adUnitId) {
        amoamo::ad::admobinterstitial::helper::callStaticVoidMethodWithString("jniInit", adUnitId.c_str());
    }

    void AdmobInterstitial::showAd() {
        amoamo::ad::admobinterstitial::helper::callStaticVoidMethod("jniShow");
    }

    bool AdmobInterstitial::isReady() {
        return amoamo::ad::admobinterstitial::helper::callStaticBoolMethod("jniIsReady");
    }

}/* ad */
}/* amoamo */

#endif /* AMOAMO_PLATFORM_IS_ANDROID */
