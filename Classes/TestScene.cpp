//
//  TestScene.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/11.
//

#include "TestScene.h"
#include "Hero.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d::ui;

bool TestScene::init()
{
    if (Scene::init())
    {
//        auto btn = Button::create("GameRes/button_20_1.png");
//        btn->setPosition(Vec2(200, 200));
//        btn->addClickEventListener([this](Ref* btn){
//            for (int i = 1; i <= 3; ++i) {
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_A_01_Skill01_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_A_01_attack_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_A_01_idle_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_A_01_move_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation("Character_A_01_death_01");
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_B_04_attackS_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_B_04_attack_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_B_04_idle01_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_B_04_idle02_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation(StringUtils::format("Character_B_04_move_0%d",i).c_str());
//                AnimationCache::getInstance()->removeAnimation("Character_B_04_death_01");
//            }
//            SpriteFrameCache::getInstance()->removeSpriteFrames();
//            Director::getInstance()->getTextureCache()->removeAllTextures();
//        });
//        this->addChild(btn);
        
        
        
//        for (int i = 0; i < 5; ++i )
//        {
//          auto texture = Director::getInstance()->getTextureCache()->addImage(StringUtils::format("guaiwu/guaiwu_%d.png",i));
//            Rect rect = Rect::ZERO;
//            rect.size = texture->getContentSize();
//            SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::createWithTexture(texture, rect), StringUtils::format("guaiwu/guaiwu_%d.png",i));
//        }
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("guaiwu/guaiwu.plist","guaiwu/guaiwu.png");
        
        auto layer = CSLoader::createNode("Csb/TestLayer.csb");
        this->addChild(layer);
        
        
        
        /**
         *
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("guaiwu/guaiwu.plist","guaiwu/guaiwu.png");
        
        batchNode = SpriteBatchNode::create("guaiwu/guaiwu.png");
        batchNode->setPosition(0,0);
        this->addChild(batchNode);
        */
        
        
        
//        srand((unsigned int)time(NULL));
//        for (int i = 0; i < 5000; i++) {
//            float rand = CCRANDOM_0_1();
//            int index = rand < 0.2f ? 0 :(rand < 0.4f ? 1 : (rand < 0.6f ? 2 : (rand < 0.8f ? 3 : 4)));
//            addSpriteToSceneWithIndex(index);
//        }
        

        return true;
    }
    return false;
    
};



void TestScene::addSpriteToSceneWithIndex(int index)
{
    auto sp = Sprite::createWithSpriteFrameName(StringUtils::format("guaiwu_%d.png",index));
    float x = CCRANDOM_0_1()*1280.f;
    float y = CCRANDOM_0_1()*620.f + 100;
    sp->setPosition(x,y);
    this->addChild(sp,CCRANDOM_0_1()*5);
    startAniamtion(sp);
}


/**
 *  通过 SpriteFrameCache 缓存来进行渲染的
 */
void TestScene::addSpriteToScene()
{
    float rand = CCRANDOM_0_1();
    int i = rand < 0.2f ? 0 :(rand < 0.4f ? 1 : (rand < 0.6f ? 2 : (rand < 0.8f ? 3 : 4)));
    auto sp = Sprite::createWithSpriteFrameName(StringUtils::format("guaiwu_%d.png",i));
    float x = CCRANDOM_0_1()*1280.f;
    float y = CCRANDOM_0_1()*620.f + 100;
    sp->setPosition(x,y);
    this->addChild(sp);
    startAniamtion(sp);
}
/**
 *  通过 SpriteBatchNode 来实现渲染的
 */
void TestScene::addSpriteToScene2()
{
    float rand = CCRANDOM_0_1();
    int i = rand < 0.2f ? 0 :(rand < 0.4f ? 1 : (rand < 0.6f ? 2 : (rand < 0.8f ? 3 : 4)));
    auto sp = Sprite::createWithSpriteFrameName(StringUtils::format("guaiwu_%d.png",i));
    float x = CCRANDOM_0_1()*1280.f;
    float y = CCRANDOM_0_1()*620.f + 100;
    sp->setPosition(x,y);
    batchNode->addChild(sp);
    startAniamtion(sp);
}

void TestScene::startAniamtion(Node* node)
{
    node->stopAllActions();
    auto callback = CallFunc::create([node,this]{
        this->startAniamtion(node);
    });
    float rand = CCRANDOM_0_1();
    int time = (int)(rand*5.f+5);
    node->runAction(Sequence::create(MoveTo::create(time, Vec2(CCRANDOM_0_1()*1280.f*(rand+0.5f), CCRANDOM_0_1()*720.f*(rand+0.5f))),callback, NULL));
}


