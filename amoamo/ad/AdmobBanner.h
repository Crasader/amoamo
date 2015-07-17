#include "amoamo/definition.h"

#ifndef AMOAMO_ADMOB_BANNER_H
#define AMOAMO_ADMOB_BANNER_H

#include "amoamo/templates/Singleton.h"

namespace amoamo{
namespace ad{

class AdmobBanner: public amoamo::templates::Singleton<AdmobBanner>
{
private:
    friend class Singleton<AdmobBanner>;
    AdmobBanner(){}
public:
    void init(std::string adUnitId);
    void hideAd();
    void showAd();
    
    bool isAdShowing;
};

} // namespace ad
} // namespace amoamo

#endif // AMOAMO_ADMOB_BANNER_H
