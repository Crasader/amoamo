#pragma once

#include <string>

namespace amoamo {
    namespace util {
        
        class String {
        public:
            static std::string urlencode(const std::string& string);
        };
        
    }// namespace util
}// namespace amoamo
