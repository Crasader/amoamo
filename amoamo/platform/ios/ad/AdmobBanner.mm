#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_IOS

#include "cocos2d.h"
#include "AdmobBanner.h"

#import <UIKit/UIKit.h>
#import "GADBannerView.h"
#import "AppController.h"

using namespace std;

@interface GADBannerViewHolder : NSObject {
}
+(GADBannerView*)bannerView;
+(void)setGADBannerView:(GADBannerView*)bannerview;
@end

@implementation GADBannerViewHolder
static GADBannerView* bannerView = nil;
+ (GADBannerView*)bannerView { return bannerView; }
+ (void)setGADBannerView:(GADBannerView*)value { bannerView = value; }
@end

namespace amoamo {

namespace ad {
    
    void AdmobBanner::init(string adUnitId)
    {
        GADBannerView* bannerView = [GADBannerViewHolder bannerView];
        if (bannerView) {
            return;
        }
        AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
        UIViewController *controller = (UIViewController *)appController.viewController;

        CGPoint adPos;
        GADAdSize adSize;
        if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone){
            adSize = kGADAdSizeBanner;
            adPos = CGPointMake(0.0, controller.view.frame.size.height - 50);
        } else {
            adSize = kGADAdSizeLeaderboard;
            adPos = CGPointMake(0.0, controller.view.frame.size.height - 90);
        }
        bannerView = [[[GADBannerView alloc] initWithAdSize:adSize origin:adPos] autorelease];
        bannerView.adUnitID = [NSString stringWithUTF8String:adUnitId.c_str()];
        bannerView.rootViewController = [[[UIApplication sharedApplication] keyWindow] rootViewController];
        GADRequest *request = [GADRequest request];
        request.testDevices = @[ GAD_SIMULATOR_ID ];
        [bannerView loadRequest:request];
        [controller.view addSubview:bannerView];
        [bannerView setRootViewController:(UIViewController *)appController.viewController];
        [GADBannerViewHolder setGADBannerView:bannerView];
    }
    
    void AdmobBanner::hideAd()
    {
        GADBannerView* bannerView = [GADBannerViewHolder bannerView];
        if (!bannerView) {
            return;
        }
        bannerView.hidden = YES;
        isAdShowing = false;
        return;
    }
    
    void AdmobBanner::showAd()
    {
        GADBannerView* bannerView = [GADBannerViewHolder bannerView];
        if (!bannerView) {
            return;
        }
        bannerView.hidden = NO;
        isAdShowing = true;
        return;
    }
    
} /* namespace ad */
} /* namespace amoamo */

#endif /* AMOAMO_PLATFORM_IS_IOS */