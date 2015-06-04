#include "amoamo/util/UtilHttp.h"

#include <iostream>
#include <stdio.h>
#include <sstream>

namespace amoamo {
    namespace util {
        
        bool Http::isStatus20X(long statusCode)
        {
            return 2 == (statusCode / 100);
        }
        
    }// namespace util
}// namespace amoamo
