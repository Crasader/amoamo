#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_IOS
#ifdef AMOAMO_ENABLE_GAME_CENTER

#import <GameCenterIos.h>
#import <GameKit/GameKit.h>
#import "AppController.h"
#import "RootViewController.h"

namespace amoamo {

    void GameCenter::login()
    {
        GKLocalPlayer* localPlayer = [GKLocalPlayer localPlayer];
        if (localPlayer.isAuthenticated) {
            return;
        }
        
        [localPlayer authenticateWithCompletionHandler:^(NSError* error) {
         if (error) {
         if (error.code != GKErrorAuthenticationInProgress) {
         NSLog(@"[GameCenter] login failed: %@", error.localizedDescription);
         }
         } else {
         [self retrieveScoresFromDevice];
         [self retrieveAchievementsFromDevice];
         }
         }];
    }
    
    bool GameCenter::showScores()
    {
        if (![GKLocalPlayer localPlayer].isAuthenticated) {
            return NO;
        }
        
        AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
        
        GKLeaderboardViewController *leaderboardViewController = [[[GKLeaderboardViewController alloc] init] autorelease];
        leaderboardViewController.timeScope = GKLeaderboardTimeScopeAllTime;
        leaderboardViewController.leaderboardDelegate = appController.viewController;
        
        [appController.viewController presentViewController:leaderboardViewController animated:YES completion:NULL];
        return YES;
    }
    
    void GameCenter::postScore(const char* idName, int score)
    {
        GKScore* gkScore = [[[GKScore alloc] init] autorelease];
        gkScore.category = [NSString stringWithUTF8String:idName];
        gkScore.value = [score longLongValue];
        gkScore.shouldSetDefaultLeaderboard = YES;
        
        if (![GKLocalPlayer localPlayer].isAuthenticated) {
            [self saveScoreToDevice:gkScore];
            return;
        }
        
        [gkScore reportScoreWithCompletionHandler:^(NSError* error) {
         if (error) {
         NSLog(@"[GameCenter] postScore for %s failed: %@", idName, error.localizedDescription);
         }
        }];
    }

} /* namespace amoamo */

#endif /* AMOAMO_ENABLE_GAME_CENTER */
#endif /* AMOAMO_PLATFORM_IS_IOS */
