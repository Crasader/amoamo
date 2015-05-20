#pragma once

#include "amoamo/definition.h"

namespace amoamo {

class GameCenter
{
public:
    static void login();
    
    static bool showScores();
    static void postScore(const char* idName, int score);
    
#ifdef AMOAMO_PLATFORM_IS_ANDROID
    void signIn();
    void signOut();
    bool isSignedIn();
#endif
    };
    
} // namespace amoamo
