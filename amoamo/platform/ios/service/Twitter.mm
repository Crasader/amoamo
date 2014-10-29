#include "amoamo/definition.h"
#ifdef AMOAMO_PLATFORM_IS_IOS

#include "cocos2d.h"
#include "amoamo/Twitter.h"

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
        tweet_string = [NSString stringWithFormat:@"https://twitter.com/intent/tweet?text=%@", tweet_string];
        tweet_string = [tweet_string stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        NSURL *url = [NSURL URLWithString:tweet_string];
        [[UIApplication sharedApplication] openURL:url];
    }
}
    
    
void Twitter::tweetWithScreenShot(const char* tweet, char const *file_path)
{
    CCLOG("Tweeting with screenshot:%s", tweet);
    NSString* tweet_string = [NSString stringWithUTF8String:tweet];
    NSString* file_path_string = [NSString stringWithUTF8String:file_path];
    
    if([SLComposeViewController isAvailableForServiceType:SLServiceTypeTwitter])
	{
		AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
        
		NSString *serviceType = SLServiceTypeTwitter;
		SLComposeViewController *composeCtl = [SLComposeViewController composeViewControllerForServiceType:serviceType];
		[composeCtl setInitialText:tweet_string];
		UIImage *image = [UIImage imageWithContentsOfFile:file_path_string];
		[composeCtl addImage:image];
		[composeCtl setCompletionHandler:^(SLComposeViewControllerResult result) {
			[appController.viewController dismissViewControllerAnimated:YES completion:nil];
			if (result == SLComposeViewControllerResultDone) {
				//投稿成功時の処理
				NSLog(@"ツイートしました");
			}
        }];
        
        [appController.viewController presentViewController:composeCtl animated:YES completion:nil];
	}
	else
	{
		tweet_string = [NSString stringWithFormat:@"https://twitter.com/intent/tweet?text=%@",tweet_string];
		tweet_string = [tweet_string stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
		NSURL *url = [NSURL URLWithString:tweet_string];
		[[UIApplication sharedApplication] openURL:url];
	}
}

} /* namespace amoamo */

#endif /* AMOAMO_PLATFORM_IS_IOS */