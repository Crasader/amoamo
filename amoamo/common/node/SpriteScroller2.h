#pragma once

#include "cocos2d.h"

USING_NS_CC;

namespace amoamo {
namespace common {
namespace node {

/*
 これで考え方が良いのかどうかわからないが、このクラスは3つのレイヤーに分かれている
 1. sprite scroll - 登録したspriteを単純に移動させる
 2. rewind range - sprite を range内でループさせる
 x, y方向の二通り設定
 3. visible range - sprite が range内から外れると setVisible(false); となる
 上下左右それぞれ個別に設定できる
 
 usage:
	// 例1: 雲を左に移動させる
	SpriteScroller spriteScroller = SpriteScroller();
	spriteScroller.setRewindRangeX(-100, display.width + 100);
	// 雲の数だけ登録する
	spriteScroller.add(雲のSprite*, Vec2(-10, 0));
	// update()等の中で呼び出す
	spriteScroller.scrollSprites(Vec2(1, 0));
	spriteScroller.rewind();
 
	// 例2: 宇宙で輝く星を範囲内でループさせつつ、見えるのは宇宙空間のみに限定する
	SpriteScroller spriteScroller = SpriteScroller();
	spriteScroller.rangeVisibleBottom(1000);// 宇宙の高さ下限
	spriteScroller.setRewindRangeX(-100, display.width + 100);
	spriteScroller.setRewindRangeY(-100, display.height + 100);
	// 星の数だけ登録する
	spriteScroller.add(Sprite*, Vec2(0, 0));
	// update() 内
	spriteScroller.scrollSprites(Vec2(x, y));
	spriteScroller.rewind();
	spriteScroller.optimizeVisible();
 */

class SpriteScroller2
{
    // 可視範囲の定義
    // この範囲外に出ると isVisible(false); となる
protected:
    bool isSetBorderVisibleTop;
    bool isSetBorderVisibleBottom;
    bool isSetBorderVisibleRight;
    bool isSetBorderVisibleLeft;
    CC_SYNTHESIZE_READONLY(float, borderVisibleTop, borderVisibleTop);
    CC_SYNTHESIZE_READONLY(float, borderVisibleBottom, borderVisibleBottom);
    CC_SYNTHESIZE_READONLY(float, borderVisibleRight, borderVisibleRight);
    CC_SYNTHESIZE_READONLY(float, borderVisibleLeft, borderVisibleLeft);
public:
    void setRangeVisibleBottom(float border) {
        isSetBorderVisibleBottom = true;
        borderVisibleBottom = border;
    }

    // 巻き戻り範囲
    // この範囲外に出ると (Top - Bottom), (Right - Left) の距離だけ巻き戻る
    CC_SYNTHESIZE(float, borderRewindTop, BorderRewindTop);
    CC_SYNTHESIZE(float, borderRewindBottom, BorderRewindBottom);
    CC_SYNTHESIZE(float, borderRewindRight, BorderRewindRight);
    CC_SYNTHESIZE(float, borderRewindLeft, BorderRewindLeft);
public:
    typedef std::pair<cocos2d::Sprite*, Vec2> scrollSprite;
    
    SpriteScroller2() {
    }
    
    /**
     * scrollするspriteの登録
     */
    void add(cocos2d::Sprite* s, Vec2 vector) {
        this->sprites.push_back(scrollSprite(s, vector));
    }
    
    /*********************************************************
     * Sprite Scroll
     */
    
    /**
     * 登録されているspriteをscrollする
     */
    virtual void scrollSprites(const Vec2 &factor) {
        for (auto scrollSprite : this->sprites) {
            auto sprite = scrollSprite.first;
            auto vector = scrollSprite.second;
            
            auto newPosition =
            sprite->getPosition() +
            Vec2(vector.x * factor.x, vector.y * factor.y);
            sprite->setPosition(newPosition);
        }
    }
    
    
    /*********************************************************
     * Rewind
     */
    
    virtual void setRewindRangeX(float left, float right) {
        this->borderRewindLeft = left;
        this->borderRewindRight = right;
    }
    
    virtual bool isSetRewindRangeX() {
        return borderRewindLeft != borderRewindRight;
    }
    
    virtual void setRewindRangeY(float bottom, float top) {
        this->borderRewindBottom = bottom;
        this->borderRewindTop = top;
    }
    
    virtual bool isSetRewindRangeY() {
        return borderRewindTop != borderRewindBottom;
    }
    
    /**
     * 登録されているrewind rangeをscrollする
     */
    virtual void moveRewindRangeX(float x) {
        this->borderRewindLeft += x;
        this->borderRewindRight += x;
    }
    virtual void moveRewindRangeY(float y) {
        this->borderRewindTop += y;
        this->borderRewindBottom += y;
    }
    virtual void rewind() {
        if (isSetRewindRangeX()) {
            float diffX = borderRewindRight - borderRewindLeft;
            for (auto scrollSprite : this->sprites) {
                auto sprite = scrollSprite.first;
                
                auto currentPosition = sprite->getPosition();
                auto newPosition = currentPosition;
                // 右に行き過ぎ
                if (borderRewindRight < currentPosition.x) {
                    int n = static_cast<int>(std::ceil((currentPosition.x - borderRewindRight) / diffX));
                    newPosition.x -= n * diffX;
                }
                // 左に行き過ぎ
                if (currentPosition.x < borderRewindLeft) {
                    int n = static_cast<int>(std::ceil(std::abs((currentPosition.x - borderRewindLeft) / diffX)));
                    newPosition.x += n * diffX;
                }
                sprite->setPosition(newPosition);
            }
        }
        if (isSetRewindRangeY()) {
            float diffY = borderRewindTop - borderRewindBottom;
            for (auto scrollSprite : this->sprites) {
                auto sprite = scrollSprite.first;
                
                auto currentPosition = sprite->getPosition();
                auto newPosition = currentPosition;
                // 上に行き過ぎ
                if (borderRewindTop < currentPosition.y) {
                    int n = static_cast<int>(std::ceil((currentPosition.y - borderRewindTop) / diffY));
                    newPosition.y -= n * diffY;
                }
                // 下に行き過ぎ
                if (currentPosition.y < borderRewindBottom) {
                    int n = static_cast<int>(std::ceil(std::abs((currentPosition.y - borderRewindBottom) / diffY)));
                    newPosition.y += n * diffY;
                }
                sprite->setPosition(newPosition);
            }
        }
    }
    
    /*********************************************************
     * Visible
     */
    
    virtual void moveVisibleBorder(cocos2d::Vec2 moves) {
        if (isSetBorderVisibleLeft) {
            borderVisibleLeft += moves.x;
        }
        if (isSetBorderVisibleRight) {
            borderVisibleRight += moves.x;
        }
        if (isSetBorderVisibleBottom) {
            borderVisibleBottom += moves.y;
        }
        if (isSetBorderVisibleTop) {
            borderVisibleTop += moves.y;
        }
    }
    
    virtual void optimizeVisible() {
        if (!isSetBorderVisibleBottom
            && !isSetBorderVisibleTop
            && !isSetBorderVisibleLeft
            && !isSetBorderVisibleRight
            ) {
            return;
        }
        // 上下
        std::function<bool(float)> fy;
        if (isSetBorderVisibleBottom && isSetBorderVisibleTop) {
            fy = [&](float y){ return borderVisibleBottom <= y && y <= borderRewindTop; };
        } else if (!isSetBorderVisibleBottom || isSetBorderVisibleTop) {
            fy = [&](float y){ return y <= borderRewindTop; };
        } else if (isSetBorderVisibleBottom || !isSetBorderVisibleTop) {
            fy = [&](float y){ return borderVisibleBottom <= y; };
        } else {
            fy = [&](float y){ return true; };
        }
        // 左右
        std::function<bool(float)> fx;
        if (isSetBorderVisibleLeft && isSetBorderVisibleRight) {
            fx = [&](float x){ return borderVisibleLeft <= x && x <= borderRewindRight; };
        } else if (!isSetBorderVisibleLeft || isSetBorderVisibleRight) {
            fx = [&](float x){ return x <= borderRewindRight; };
        } else if (isSetBorderVisibleLeft || !isSetBorderVisibleRight) {
            fx = [&](float x){ return borderVisibleLeft <= x; };
        } else {
            fx = [&](float x){ return true; };
        }
        for (auto scrollSprite : this->sprites) {
            auto sprite = scrollSprite.first;
            auto currentPosition = sprite->getPosition();
            sprite->setVisible(fy(currentPosition.y) && fx(currentPosition.x));
        }
    }
private:
    std::vector<scrollSprite> sprites;
};
}// namespace node
}// namespace common
}// namespace amoamo
