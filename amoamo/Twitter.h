#ifndef AMOAMO_TWITTER_H
#define AMOAMO_TWITTER_H

#include "amoamo/definition.h"

namespace amoamo
{

class Twitter
{
public:
    static void tweet(const char* $tweet);
    static void aaa() {
    	CCLOG("aaaaaaaaaaaaaaaa");
    };
    //static void tweetScreenShot(const char* $tweet);
};

} // namespace amoamo

#endif /* AMOAMO_TWITTER_H */
