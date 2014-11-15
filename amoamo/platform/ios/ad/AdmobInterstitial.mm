#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_IOS

#include "cocos2d.h"
#include "AdmobInterstitial.h"

#import <UIKit/UIKit.h>
#import "GADInterstitial.h"
#import "AppController.h"

using namespace std;

@interface GADInterstitialViewHolder : NSObject {
}
+(GADInterstitial*)bannerView;
+(void)setGADInterstitialView:(GADInterstitial*)bannerview;
@end

@implementation GADInterstitialViewHolder
static GADInterstitial* bannerView = nil;
+ (GADInterstitial*)bannerView { return bannerView; }
+ (void)setGADInterstitialView:(GADInterstitial*)value { bannerView = value; }
@end

namespace amoamo {

namespace ad {
    
    void AdmobInterstitial::init(string adUnitId)
    {
        this->adUnitId = adUnitId;
        load();
    }
    
    void AdmobInterstitial::load()
    {
        bannerView = [[GADInterstitial alloc] init];
        bannerView.adUnitID = [NSString stringWithUTF8String:adUnitId.c_str()];
        GADRequest *request = [GADRequest request];
        request.testDevices = @[ GAD_SIMULATOR_ID ];
        [bannerView loadRequest:request];
        
        [GADInterstitialViewHolder setGADInterstitialView:bannerView];
    }
    
    void AdmobInterstitial::showAd()
    {
        GADInterstitial* bannerView = [GADInterstitialViewHolder bannerView];
        if (!bannerView) {
            return;
        }
        if ([bannerView isReady]) {
            AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
            [bannerView presentFromRootViewController:(UIViewController *)appController.viewController];
        }
    }
    
    bool AdmobInterstitial::isReady()
    {
        GADInterstitial* bannerView = [GADInterstitialViewHolder bannerView];
        if (!bannerView) {
            return false;
        }
        return [bannerView isReady];
    }
    
} /* namespace ad */
} /* namespace amoamo */

#endif /* AMOAMO_PLATFORM_IS_IOS */