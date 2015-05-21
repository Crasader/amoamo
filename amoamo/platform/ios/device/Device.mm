#import "Reachability.h"

#include "cocos2d.h"
#include "amoamo/Device.h"

namespace amoamo {
    
bool Device::isConnectedInternet()
{
    Reachability *reach = [Reachability reachabilityForInternetConnection];
    NetworkStatus netStatus = [reach currentReachabilityStatus];
    return netStatus != NotReachable;
}

}