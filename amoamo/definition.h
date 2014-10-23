#ifndef AMOAMO_DEFINITION_H
#define AMOAMO_DEFINITION_H

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define AMOAMO_PLATFORM_IS_IOS
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define AMOAMO_PLATFORM_IS_ANDROID
#endif

#include "amoamo/config.h"

#endif /* AMOAMO_DEFINITION_H */
