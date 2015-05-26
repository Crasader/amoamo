#include "amoamo/util/UtilString.h"

#include <iostream>
#include <stdio.h>
#include <sstream>

namespace amoamo {
    namespace util {
        
        std::string String::urlencode(const std::string& string)
        {
            std::ostringstream os;
            for (int i = 0; i < string.size(); i++) {
                char c = string[i];
                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                    (c >= '0' && c <= '9') ||
                    c == '-' || c == '_' || c == '.' || c == '~') {
                    os << c;
                } else {
                    char s[4];
                    snprintf(s, sizeof(s), "%%%02x", c & 0xff);
                    os << s;
                }
            }
            return os.str();
        }
        
    }// namespace util
}// namespace amoamo
