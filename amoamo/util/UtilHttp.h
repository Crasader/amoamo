#pragma once

#include <string>

namespace amoamo {
    namespace util {
        
        class Http {
        public:
            static bool isStatus20X(long statusCode);
        };
        
    }// namespace util
}// namespace amoamo
