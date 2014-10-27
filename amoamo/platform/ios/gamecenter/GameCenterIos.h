#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_IOS
#ifdef AMOAMO_ENABLE_GAME_CENTER

#import <GameKit/GameKit.h>

@interface GameCenterIos : UIViewController<GKGameCenterControllerDelegate>

//+ (GameCenterIos*)shared;

@end

#endif /* AMOAMO_ENABLE_GAME_CENTER */
#endif /* AMOAMO_PLATFORM_IS_ANDROID */
