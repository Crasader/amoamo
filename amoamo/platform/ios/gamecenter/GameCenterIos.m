#ifdef AMOAMO_PLATFORM_IS_IOS
#ifdef AMOAMO_ENABLE_GAME_CENTER

#import <GameKit/GameKit.h>

/**
 * GameCenterにログインしているか確認処理
 * ログインしていなければログイン画面を表示
 */
- (void)authenticateLocalPlayer
{
    GKLocalPlayer* player = [GKLocalPlayer localPlayer];
    player.authenticateHandler = ^(UIViewController* ui, NSError* error )
    {
        if( nil != ui )
        {
            [self presentViewController:ui animated:YES completion:nil];
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
- (IBAction)showRanking:(id)sender {
    GKGameCenterViewController *gcView = [GKGameCenterViewController new];
    if (gcView != nil)
    {
        gcView.gameCenterDelegate = self;
        gcView.viewState = GKGameCenterViewControllerStateLeaderboards;
        [self presentViewController:gcView animated:YES completion:nil];
    }
}

/**
 * リーダーボードで完了タップ時の処理
 * 前の画面に戻る
 */
- (void)gameCenterViewControllerDidFinish:(GKGameCenterViewController *)gameCenterViewController
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

#endif /* AMOAMO_ENABLE_GAME_CENTER */
#endif /* AMOAMO_PLATFORM_IS_IOS */
