#include "amoamo/definition.h"
#ifdef AMOAMO_ENABLE_GAME_CENTER

#ifndef AMOAMO_GAMECENTER_H
#define AMOAMO_GAMECENTER_H

namespace amoamo {

class GameCenter
{
public:
    void login();
    
    bool showAchievements();
    void postAchievement(const char* idName, int percentComplete);
    void clearAllAchievements();
    
    bool showScores();
    void postScore(const char* idName, int score);
    void clearAllScores();
    
#ifdef AMOAMO_PLATFORM_IS_ANDROID
    void signIn();
    void signOut();
    bool isSignedIn();
#endif
    };
    
} // namespace amoamo

#endif /* AMOAMO_GAMECENTER_H */
#endif /* AMOAMO_ENABLE_GAME_CENTER */
