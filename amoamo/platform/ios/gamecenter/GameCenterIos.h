#import <GameKit/GameKit.h>

@interface GameCenterIos : UIViewController<GKGameCenterControllerDelegate>

- (void)authenticateLocalPlayer;
- (void)viewDidLoad;

- (BOOL)showLeaderBoards;
- (void)gameCenterViewControllerDidFinish:(GKGameCenterViewController *)gameCenterViewController;

- (void)postScore:(NSString*)idName score:(NSNumber*)score;

@end
