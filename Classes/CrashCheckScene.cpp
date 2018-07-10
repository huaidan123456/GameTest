//
//  CrashCheckScene.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/20.
//

#include "CrashCheckScene.h"

bool CrashCheckScene::init()
{
    if (Scene::init()) {
        
        loadSubview();
        return true;
    }
    return false;
}


void CrashCheckScene::update(float delta)
{
    if (sp1->getBoundingBox().intersectsRect(sp2->getBoundingBox())) {
        CCLOG("碰撞啦  sp2");
    }
    
    if (sp1->getBoundingBox().intersectsRect(sp3->getBoundingBox())) {
        CCLOG("碰撞啦  sp3");
    }
    
    if (sp1->getBoundingBox().intersectsRect(sp4->getBoundingBox())) {
        CCLOG("碰撞啦  sp4");
    }
    
    if (sp1->getBoundingBox().intersectsRect(sp00->getBoundingBox())) {
        CCLOG("碰撞啦  sp00");
    }
}


void CrashCheckScene::loadSubview()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("guaiwu/guaiwu.plist","guaiwu/guaiwu.png");
    sp1 = Sprite::createWithSpriteFrameName("guaiwu_0.png");
    sp1->setPosition(100.f, 100.f);
    this->addChild(sp1);

    
    sp2 = Sprite::createWithSpriteFrameName("guaiwu_1.png");
    sp2->setPosition(800.f, 100.f);
    this->addChild(sp2);
    
    

    
    
    sp3 = Sprite::createWithSpriteFrameName("guaiwu_2.png");
    sp3->setPosition(100.f, 500.f);
    this->addChild(sp3);
    
    
    
    
    
    sp4 = Sprite::createWithSpriteFrameName("guaiwu_3.png");
    sp4->setPosition(800.f, 500.f);
    this->addChild(sp4);
    
    
    
    sp00 = Sprite::create(AutoPolygon::generatePolygon("guaiwu/guaiwu_03.png"));
    sp00->setPosition(640, 360);
    this->addChild(sp00);
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [this](Touch* touch, Event* evnt)->bool
    {
        CCLOG("Layer onTouchBegan  (%f,%f)",touch->getLocation().x,touch->getLocation().y);
        auto sp1Rect = sp1->getBoundingBox();
        if (sp1Rect.containsPoint(touch->getLocation())) {

            return true;
        }

        return false;
    };
    listener->onTouchMoved = [this](Touch* touch, Event* evnt)
    {
        
        CCLOG("Layer touch  move  (%f,%f)",touch->getLocation().x,touch->getLocation().y);
        sp1->setPosition(touch->getLocation());
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    auto listener2 = EventListenerTouchOneByOne::create();
    listener2->setSwallowTouches(false);
    listener2->onTouchBegan = [this](Touch* touch, Event* evnt)->bool
    {
        CCLOG("onTouchBegan  (%f,%f)",touch->getLocation().x,touch->getLocation().y);
        return true;
    };
    listener2->onTouchMoved = [this](Touch* touch, Event* evnt)
    {
        
        CCLOG("touch  move  (%f,%f)",touch->getLocation().x,touch->getLocation().y);
        sp00->setPosition(touch->getLocation());
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener2, sp00);
    
    
    
    scheduleUpdate();
    
}
