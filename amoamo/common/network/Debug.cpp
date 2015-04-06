#include "amoamo/common/network/Debug.h"
#include "cocos2d.h"
#include "network/HttpClient.h"

USING_NS_CC;

namespace amoamo {
namespace common {
namespace network {
    
    
    const int Debug::RESPONSE_STATUS_SUCCEED = 0;
    const int Debug::RESPONSE_STATUS_TIMEOUT = 1;
    const int Debug::RESPONSE_STATUS_FAILED  = 2;
    
    void Debug::delay(
                      const std::function<void()> &succeed,
                      const std::function<void()> &timeout,
                      const std::function<void()> &failed,
                      int responseStatus,
                      int seconds) {
        
        auto url = StringUtils::toString("http://httpbin.org/delay/" + StringUtils::toString(seconds));
        auto request = new cocos2d::network::HttpRequest();
        request->setUrl(url.c_str());
        request->setRequestType(cocos2d::network::HttpRequest::Type::GET);
        request->setResponseCallback([=](cocos2d::network::HttpClient* client, cocos2d::network::HttpResponse* response){
            switch (responseStatus) {
                case RESPONSE_STATUS_SUCCEED:
                    succeed();
                    break;
                case RESPONSE_STATUS_TIMEOUT:
                    timeout();
                    break;
                case RESPONSE_STATUS_FAILED:
                    failed();
                    break;
                default:
                    throw new std::runtime_error("response status does not match.");
                    break;
            }
        });
        auto client = cocos2d::network::HttpClient::getInstance();
        client->enableCookies("");
        client->setTimeoutForConnect(10);
        client->setTimeoutForRead(10);
        client->send(request);
        request->release();
    }
    
    void Debug::delay(const cocos2d::network::ccHttpRequestCallback &callback, int seconds) {
        auto url = StringUtils::toString("http://httpbin.org/delay/" + StringUtils::toString(seconds));
        auto request = new cocos2d::network::HttpRequest();
        request->setUrl(url.c_str());
        request->setRequestType(cocos2d::network::HttpRequest::Type::GET);
        request->setResponseCallback(callback);
        auto client = cocos2d::network::HttpClient::getInstance();
        client->enableCookies("");
        client->setTimeoutForConnect(10);
        client->setTimeoutForRead(10);
        client->send(request);
        request->release();
    }
    
}// namespace network
}// namespace common
}// namespace amoamo