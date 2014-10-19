#ifndef AMOAMO_GAMECENTER_H
#define AMOAMO_GAMECENTER_H

#include <amoamo/definition.h>

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
    
#if AMOAMO_PLATFORM_IS_ANDROID
    void signIn();
    void signOut();
    bool isSignedIn();
#endif
    };
    
} // namespace amoamo

#endif /* AMOAMO_GAMECENTER_H */
