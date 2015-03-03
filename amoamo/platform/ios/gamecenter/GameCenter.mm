#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_IOS
#ifdef AMOAMO_ENABLE_GAME_CENTER

#import "amoamo/GameCenter.h"
#include <GameCenterIos.h>

namespace amoamo {

    void GameCenter::login()
    {
        CCLOG("GameCenter::login()");
        [[GameCenterIos new] authenticateLocalPlayer];
    }
    
#pragma mark -
#pragma mark Leaderboard
    
    bool GameCenter::showScores()
    {
        return [[GameCenterIos new] showLeaderBoards];
    }
    
    void GameCenter::postScore(const char* idName, int score)
    {
        
        [[GameCenterIos new] postScore:[NSString stringWithUTF8String:idName] score:[NSNumber numberWithInt:score]];
    }
    
} /* namespace amoamo */

#endif /* AMOAMO_ENABLE_GAME_CENTER */
#endif /* AMOAMO_PLATFORM_IS_IOS */
