#pragma once

namespace amoamo
{

class Twitter
{
public:
    static void tweet(const char* tweet);
    
    /*
        // usage
        utils::captureScreen([&](bool succeed, const std::string &fileName){
            if(succeed) {
                amoamo::Twitter::tweetWithScreenShot("teest ettsetses", fileName.c_str());
            } else {
                // 失敗時の処理
            }
        }, "screenshot.jpg");
     */
    static void tweetWithScreenShot(const char* tweet, const char *file_path);
};

} // namespace amoamo
