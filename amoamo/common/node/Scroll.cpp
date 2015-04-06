#include "amoamo/common/node/Scroll.h"

USING_NS_CC;
using namespace ui;

namespace amoamo {
namespace common {
namespace node {
    
    
    Node* Scroll::createNode(/* :TODO */) {
        auto node = Node::create();
        
        
        
        return node;
    }
    
}// namespace node
}// namespace common
}// namespace amoamo

/*
//画面サイズ取得
auto size = Director::getInstance()->getVisibleSize();
auto padding_x = 100;
auto padding_y = 400;
auto scroll_width = size.width - padding_x;
auto scroll_height = size.height - padding_y;

//画面サイズでスクロールビューを作る
auto *pScrollView = ScrollView::create(size);

//スクロールビューに入れるスプライトを用意
//auto *pSprite = Sprite::create("bg.jpg");

//auto *pSprite = Sprite::create("bg.jpg", Rect(0, 0, scroll_width, scroll_height));
Texture2D *bgTexture = Director::getInstance()->getTextureCache()->addImage("bg01.jpg");
const Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};

auto *pSprite = Sprite::createWithTexture(bgTexture, Rect(0, 0, scroll_width, scroll_height*2));
pSprite->getTexture()->setTexParameters(tp);

int i = 1;
for (auto it = parse_objects.begin(); it != parse_objects.end(); ++it) {
    //CCLOG("####### %s: %f", (*it).asString("name").c_str(), (*it).asDouble("score"));
    auto text = Label::createWithSystemFont((*it).asString("name") + ":" + std::to_string((*it).asDouble("score")), "HiraKakuProN-W6", 24);
    text->setPosition(Point(10, (scroll_height*2) - (30*i++)));
    text->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
    pSprite->addChild(text);
}

pScrollView->setContainer(pSprite);
pScrollView->setContentOffset(Vec2(0, -scroll_height));// containeの後に書く事
pScrollView->setContentSize(Size(scroll_width, scroll_height*2));
pScrollView->setViewSize(Size(scroll_width, scroll_height));
pScrollView->setPosition(padding_x/2, padding_y/2);
pScrollView->setDirection(ScrollView::Direction::VERTICAL);
*/