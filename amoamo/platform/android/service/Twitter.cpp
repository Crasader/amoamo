#include <definition.h>
#if AMOAMO_PLATFORM_IS_ANDROID

#include "Twitter.h"

namespace amoamo {
    
void Twitter::tweet(const char* tweet) {
    CCLOG("Android");
}
    
}

#endif /* AMOAMO_PLATFORM_IS_ANDROID */