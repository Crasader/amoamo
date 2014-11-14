#include "amoamo/definition.h"
//#ifdef AMOAMO_ENABLE_SERVICE_TWITTER

#ifndef AMOAMO_ADMOB_HELPER_H
#define AMOAMO_ADMOB_HELPER_H

#include "amoamo/templates/Singleton.h"

using namespace std;

namespace amoamo{
namespace ad{

class AdmobBanner: public amoamo::templates::Singleton<AdmobBanner>
{
private:
    friend class Singleton<AdmobBanner>;
    AdmobBanner(){}
public:
    void init(string adUnitId);
    void hideAd();
    void showAd();
    
    bool isAdShowing;
};

} // namespace ad
} // namespace amoamo

#endif // AMOAMO_ADMOB_HELPER_H