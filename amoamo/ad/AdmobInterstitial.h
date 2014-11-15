#include "amoamo/definition.h"
//#ifdef AMOAMO_ENABLE_SERVICE_TWITTER

#ifndef AMOAMO_ADMOB_INTERSTITIAL_H
#define AMOAMO_ADMOB_INTERSTITIAL_H

#include "amoamo/templates/Singleton.h"

namespace amoamo{
namespace ad{

class AdmobInterstitial: public amoamo::templates::Singleton<AdmobInterstitial>
{
private:
    friend class Singleton<AdmobInterstitial>;
    AdmobInterstitial(){}
public:
    void init(std::string adUnitId);
    void load();
    void showAd();
    bool isReady();
    
    std::string adUnitId;
};

} // namespace ad
} // namespace amoamo

#endif // AMOAMO_ADMOB_INTERSTITIAL_H