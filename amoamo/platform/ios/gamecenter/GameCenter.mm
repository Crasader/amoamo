#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_IOS
#ifdef AMOAMO_ENABLE_GAME_CENTER

#import "amoamo/GameCenter.h"
#import <GameCenterIos.h>
#import <GameKit/GameKit.h>

namespace amoamo {

    void GameCenter::login()
    {
        //[GameCenterIos viewDidLoad];
        // ここは何を書けばいいんでしょうか？
    }

} /* namespace amoamo */

#endif /* AMOAMO_ENABLE_GAME_CENTER */
#endif /* AMOAMO_PLATFORM_IS_IOS */
