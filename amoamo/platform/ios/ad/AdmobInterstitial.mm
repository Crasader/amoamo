#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_IOS

#include "cocos2d.h"
#include "AdmobInterstitial.h"

#import <UIKit/UIKit.h>
#import <GoogleMobileAds/GADInterstitial.h>
#import <GoogleMobileAds/GADInterstitialDelegate.h>
#import "AppController.h"

// https://developers.google.com/mobile-ads-sdk/docs/admob/ios/interstitial

using namespace std;

@interface GADInterstitialViewHolder : NSObject<GADInterstitialDelegate>
+(GADInterstitialViewHolder*)instance;
@property(nonatomic, strong) GADInterstitial *interstitial;
@property(nonatomic, retain) NSString* adUnitId;
@end

@implementation GADInterstitialViewHolder
static GADInterstitialViewHolder* instance = [[GADInterstitialViewHolder alloc] init];
+ (GADInterstitialViewHolder*)instance { return instance; }
- (void)initialize:(NSString*)adUnitId {
    self.adUnitId = adUnitId;
    [self createAndLoadInterstitial];
}
- (void)interstitialDidDismissScreen:(GADInterstitial *)interstitial {
    self.interstitial = [self createAndLoadInterstitial];
}
- (GADInterstitial *)getInterstitial {
    return self.interstitial;
}
- (GADInterstitial *)createAndLoadInterstitial {
    self.interstitial = [[GADInterstitial alloc] init];
    self.interstitial.adUnitID = self.adUnitId;
    self.interstitial.delegate = self;
    GADRequest *request = [GADRequest request];
    //request.testDevices = @[ GAD_SIMULATOR_ID ];
    [self.interstitial loadRequest:request];
    return self.interstitial;
}
@end

namespace amoamo {

namespace ad {
    
    void AdmobInterstitial::init(string adUnitId)
    {
        GADInterstitialViewHolder* holder = [GADInterstitialViewHolder instance];
        [holder initialize:[NSString stringWithUTF8String:adUnitId.c_str()]];
    }
    
    void AdmobInterstitial::showAd()
    {
        GADInterstitialViewHolder* holder = [GADInterstitialViewHolder instance];
        GADInterstitial* interstitial = [holder getInterstitial];
        if ([interstitial isReady]) {
            AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
            [interstitial presentFromRootViewController:(UIViewController *)appController.viewController];
        }
    }
    
    bool AdmobInterstitial::isReady()
    {
        GADInterstitialViewHolder* holder = [GADInterstitialViewHolder instance];
        GADInterstitial* interstitial = [holder getInterstitial];
        return [interstitial isReady];
    }
    
} /* namespace ad */
} /* namespace amoamo */

#endif /* AMOAMO_PLATFORM_IS_IOS */