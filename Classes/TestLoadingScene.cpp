//
//  TestLoadingScene.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/29.
//

#include "TestLoadingScene.h"
#include "TestWelcomeScene.h"

TestLoadingScene::~TestLoadingScene()
{
    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
    Director::getInstance()->getTextureCache()->removeUnusedTextures();
}



void TestLoadingScene::onLoadLoading()
{
    showText = Text::create();
    showText->setString("Loading.....0%");
    showText->setTextColor(Color4B(Color3B::YELLOW));
    showText->setPosition(Vec2(640, 500));
    showText->setFontSize(48.f);
    this->addChild(showText);
}


void TestLoadingScene::onLoadResources()
{
    for (int i = 1; i < 73; ++i) {
        int number = 10000+i;
        addImageAsync(StringUtils::format("ReXueRes/model/%d/%d_walk.png",number,number));
        addImageAsync(StringUtils::format("ReXueRes/model/%d/%d_die.png",number,number));
        addImageAsync(StringUtils::format("ReXueRes/model/%d/%d_hurt.png",number,number));
    }
}


void TestLoadingScene::onLoadResourcesProgress(float percent)
{
    showText->setString(StringUtils::format("Loading.....%f",percent));
}
void TestLoadingScene::onLoadResourcesCompleted()
{
    clock_t start = clock();
    for (int i = 1; i < 73; ++i) {
        int number = 10000+i;
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(StringUtils::format("ReXueRes/model/%d/%d_walk.plist",number,number));
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(StringUtils::format("ReXueRes/model/%d/%d_die.plist",number,number));
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(StringUtils::format("ReXueRes/model/%d/%d_hurt.plist",number,number));
    }
    clock_t end   = clock();
    CCLOG("onLoadResourcesCompleted() 话费的时间 = %f",(float)(end - start) / CLOCKS_PER_SEC);
    
    showText->setString("完成");
    
}
void TestLoadingScene::onLoadScene()
{
    this->removeAllChildren();
    
    srand((unsigned int)time(nullptr));
    int number = 10000+(int)(CCRANDOM_0_1()*72);
    hero = Sprite::createWithSpriteFrameName(StringUtils::format("%d_walk_0000.png",number));
    hero->setPosition(Vec2(640, 200));
    this->addChild(hero);
    auto anim = Animation::create();
    for (int i = 0; i < 8; ++i)
    {
        anim->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("%d_walk_000%d.png",number,i)));
    }
    // 播放间隔
    anim->setDelayPerUnit(0.12f);
    // 设置动画结束后是否恢复到原来的帧
    anim->setRestoreOriginalFrame(true);
    // 循环的次数  -1表示无限循环
    anim->setLoops(-1);
    
    hero->runAction(Animate::create(anim));
    
    
    
    auto btn = Button::create("GameRes/btn_01_01.png");
    btn->setPosition(Vec2(50, 50));
    btn->addClickEventListener([this](Ref* btn){
        Director::getInstance()->replaceScene(TestWelcomeScene::create());
    });
    this->addChild(btn);
}
