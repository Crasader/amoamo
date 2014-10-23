#include "amoamo/definition.h"
#ifdef AMOAMO_ENABLE_SERVICE_TWITTER

#ifndef AMOAMO_TWITTER_H
#define AMOAMO_TWITTER_H

namespace amoamo
{

class Twitter
{
public:
    static void tweet(const char* $tweet);
    //static void tweetWithScreenShot(const char* $tweet);
};

} // namespace amoamo

#endif /* AMOAMO_TWITTER_H */
#endif /* AMOAMO_ENABLE_SERVICE_TWITTER */
