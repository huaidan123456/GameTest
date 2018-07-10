//
//  TestWelcomeScene.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/29.
//

#include "TestWelcomeScene.h"
#include "TestLoadingScene.h"
#include "CsvUtil.h"
#include "CCCsvHelper.h"
#include "ALCsvUtil.h"

bool TestWelcomeScene::init()
{
    if (Scene::init()) {
        
        
        auto btn1 = Button::create("GameRes/button_20_1.png");
        btn1->setPosition(Vec2(640, 300));
        btn1->addClickEventListener([this](Ref* btn){
//            CsvUtil::getInstance()->addFileData("CSV/level.csv");
//            std::string str1 = CsvUtil::getInstance()->getText(0, 0, "CSV/level.csv");
//            CCLOG("str1 = %s",str1.c_str());
//            GCCsvHelper* pHelper = new GCCsvHelper("CSV/level.csv");
//            std::string str2 = pHelper->getData(0, 0);
//            CCLOG("str2 = %s",str2.c_str());
//            ALCsvUtil::getInstance()->addFileData("CSV/level.csv");
//            std::string str3 = ALCsvUtil::getInstance()->getText(99, 2, "CSV/level.csv");
//            CCLOG("str3 = %s",str3.c_str());

            CCLOG("点击啦啦啦啦啦");
        });
        btn1->addTouchEventListener([this](Ref* ref,Widget::TouchEventType type){
            CCLOG("点击啦啦啦啦啦");
        });
        
        
        btn1->setFlippedY(true);
        this->addChild(btn1);
        
        
        
        
        auto btn = Button::create("GameRes/btn_01_01.png");
        btn->setPosition(Vec2(300, 120));
        btn->addClickEventListener([this](Ref* btn){
//            Director::getInstance()->replaceScene(TestLoadingScene::create());
            CCLOG("adfasdf");
        });
        btn->setFlippedY(true);
        this->addChild(btn);
        
        
//        auto sp = Sprite::create("GameRes/button_20_1.png");
//        sp->setPosition(Vec2(100,300));
//        
//        this->addChild(sp);
//        
//        auto lis = EventListenerTouchOneByOne::create();
//        lis->setSwallowTouches(false);
//        lis->onTouchBegan = [this](Touch* touch, Event* evnt)->bool
//        {
//            CCLOG("asdfasdfasdfasd  begin");
//            return true;
//        };
//        
//        lis->onTouchMoved = [this](Touch* touch, Event* evnt){
//            CCLOG("asdfasdfasdfasd  move");
//        };
//        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lis, sp);
        
        
        
//        auto listener = EventListenerTouchOneByOne::create();
//        listener->setSwallowTouches(true);
//        listener->onTouchBegan = [this](Touch* touch, Event* evnt)->bool
//        {
//            return true;
//        };
//
//        listener->onTouchMoved = [this](Touch* touch, Event* evnt){
//            CCLOG("move");
//        };

        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = [this](const std::vector<Touch*>& touchs, Event* event)->void
        {
            CCLOG("begin");
        };

        listener->onTouchesMoved = [this](const std::vector<Touch*>& touchs, Event* event){
            CCLOG("move");
        };
        
        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
        
        
        
        
        
        return true;
    }
    return false;
}
