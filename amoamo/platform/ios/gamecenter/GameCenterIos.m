#import <GameCenterIos.h>
#import <GameKit/GameKit.h>
#import "AppController.h"
#import "RootViewController.h"

@implementation GameCenterIos

/**
 * GameCenterにログインしているか確認処理
 * ログインしていなければログイン画面を表示
 */
-(void)authenticateLocalPlayer
{
    AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
    
    GKLocalPlayer* player = [GKLocalPlayer localPlayer];
    player.authenticateHandler = ^(UIViewController* ui, NSError* error) {
        if (error) {
            NSLog(@"[GameCenter] login failed: %@", error.localizedDescription);
        } else {
            [appController.viewController presentViewController:ui animated:YES completion:nil];
        }
    };
}

/**
 * 画面を読み込む際の処理
 */
- (void)viewDidLoad
{
    [super viewDidLoad];
    [self authenticateLocalPlayer];
}

/**
 * ランキングボタンタップ時の処理
 * リーダーボードを表示
 */
- (BOOL)showLeaderBoards {
    if (![GKLocalPlayer localPlayer].isAuthenticated) {
        return NO;
    }
    GKGameCenterViewController *gcView = [GKGameCenterViewController new];
    if (gcView != nil) {
        return NO;
    }
    AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
    
    gcView.gameCenterDelegate = appController.viewController;
    gcView.viewState = GKGameCenterViewControllerStateLeaderboards;
    [appController.viewController presentViewController:gcView animated:YES completion:nil];
    return YES;
}

// GameCenter 完了 callback
- (void)gameCenterViewControllerDidFinish:(GKGameCenterViewController *)gameCenterViewController
{
    AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
    [appController.viewController dismissViewControllerAnimated:YES completion:nil];
}

/**
 * スコアの送信
 */
- (void)postScore:(NSString*)idName score:(NSNumber*)score
{
    if ([GKLocalPlayer localPlayer].isAuthenticated) {
        GKScore* score = [[GKScore alloc] initWithLeaderboardIdentifier:idName];
        score.value = score;
        [GKScore reportScores:@[score] withCompletionHandler:^(NSError *error) {
            if (error) {
                // エラーの場合
            }
        }];
    }
}

@end

