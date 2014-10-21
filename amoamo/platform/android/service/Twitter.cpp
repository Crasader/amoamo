#include "amoamo/definition.h"
#if AMOAMO_PLATFORM_IS_ANDROID

#include "amoamo/Twitter.h"
#include <jni.h>
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

namespace amoamo {

namespace helper {
namespace twitter {

    const char* const CLASS_NAME = "com/amoamo/service/Twitter";

    
	void callStaticVoidMethodWithString(const char* name, const char* c_string)
	{
        CCLOG("### callStaticVoidMethodWithString start");
		cocos2d::JniMethodInfo t;
		if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "(Ljava/lang/String;)V")) {
			jstring j_string = t.env->NewStringUTF(c_string);
			t.env->CallStaticVoidMethod(t.classID, t.methodID, j_string);
			t.env->DeleteLocalRef(t.classID);
			t.env->DeleteLocalRef(j_string);
		}
        CCLOG("### callStaticVoidMethodWithString end");
	}
} /* helper */
} /* twitter */
    
    void Twitter::tweet(const char* tweet) {
        CCLOG("Android Android Android");
        amoamo::helper::twitter::callStaticVoidMethodWithString("tweet", tweet);
    }

}/* amoamo */

#endif /* AMOAMO_PLATFORM_IS_ANDROID */
