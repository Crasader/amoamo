#include <definition.h>
#if AMOAMO_PLATFORM_IS_IOS

#include "Twitter.h"

#import "AppController.h"
#import <Social/Social.h>

namespace amoamo {
    
void Twitter::tweet(const char* tweet)
{
    CCLOG("Tweeting:%s", tweet);
    NSString* tweet_string = [NSString stringWithUTF8String:tweet];
    
    if ([SLComposeViewController isAvailableForServiceType:SLServiceTypeTwitter]) {
        SLComposeViewController *tweetSheet = [SLComposeViewController composeViewControllerForServiceType:SLServiceTypeTwitter];
        [tweetSheet setInitialText:tweet_string];
        [tweetSheet setCompletionHandler:^(SLComposeViewControllerResult result) {
            if (result == SLComposeViewControllerResultDone) {
                //投稿成功時の処理
            }
        }];
        UIViewController* rootController = [UIApplication sharedApplication].keyWindow.rootViewController;
        [rootController presentViewController:tweetSheet animated:YES completion:nil];
    }
    else
    {
        tweet_string = [NSString stringWithFormat:@"http://twitter.com/home?status=%@", tweet_string];
        tweet_string = [tweet_string stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        NSURL *url = [NSURL URLWithString:tweet_string];
        [[UIApplication sharedApplication] openURL:url];
    }
}

} /* namespace amoamo */

#endif /* AMOAMO_PLATFORM_IS_IOS */