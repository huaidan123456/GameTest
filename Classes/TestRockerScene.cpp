//
//  TestRockerScene.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/22.
//

#include "TestRockerScene.h"





bool TestRockerScene::init()
{
    if (Scene::init()) {
        loadSubview();
        return true;
    }
    return false;
}


void TestRockerScene::update(float delta)
{
    
}


void TestRockerScene::loadSubview()
{
    showText = Text::create();
    showText->setString("方向: 静止, 状态:静止");
    showText->setTextColor(Color4B(Color3B::YELLOW));
    showText->setPosition(Vec2(640, 680));
    showText->setFontSize(32.f);
    this->addChild(showText);
    
    
    
    rocker = GameRocker::createWithFilename("GameRes/rockerBar.png", "GameRes/rockerBG.png");
    rocker->setPosition(Vec2(640, 360));
    rocker->setupDirectionStateCallback([this](const GameRockerState& state){
        std::vector<std::string> dirVec {"静止","左","左上","上","右上","右","右下","下","左下"};
        std::vector<std::string> speedVec {"静止","正常","加速"};
        int d = 0;
        int s = 0;
        
        switch (state.getDirection()) {
            case GameRockerState::DirectionType::StayType: d = 0;break;
            case GameRockerState::DirectionType::LeftType: d = 1;break;
            case GameRockerState::DirectionType::LeftUpType: d = 2;break;
            case GameRockerState::DirectionType::UpType: d = 3;break;
            case GameRockerState::DirectionType::RightUpType: d = 4;break;
            case GameRockerState::DirectionType::RightType: d = 5;break;
            case GameRockerState::DirectionType::RightDownType: d = 6;break;
            case GameRockerState::DirectionType::DownType: d = 7;break;
            case GameRockerState::DirectionType::LeftDownType: d = 8;break;
            default: break;
        }
        switch (state.getSpeedState()) {
            case GameRockerState::SpeedState::StayState: s = 0; break;
            case GameRockerState::SpeedState::NormalState: s = 1; break;
            case GameRockerState::SpeedState::QuickState: s = 2; break;
                
            default:
                break;
        }
        showText->setString(StringUtils::format("方向：%s,状态 :%s",dirVec.at(d).c_str(),speedVec.at(s).c_str()));
    });
    rocker->setMovable(true);
    rocker->setMoveRect(Rect(0, 0, 640, 360));
    rocker->setKeysType(GameRocker::KeysType::Key_8);
    
    this->addChild(rocker);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(false);
    listener->onTouchBegan = [this](Touch* touch, Event* evnt)->bool{
        CCLOG("UUUUUUUULayer onTouchBegan  (%f,%f)",touch->getLocation().x,touch->getLocation().y);
        
        rocker->setPosition(touch->getLocation());
        rocker->setVisible(true);
        rocker->setEnable(true);
        
        return true;
    };
    
    listener->onTouchMoved = [this](Touch* touch, Event* evnt)
    {
        CCLOG("LLLLLLayer touch  move  (%f,%f)",touch->getLocation().x,touch->getLocation().y);
    };
    
    listener->onTouchCancelled = [this](Touch* touch, Event* evnt)
    {
        rocker->setVisible(false);
        rocker->setEnable(false);
    };
    
    listener->onTouchEnded = [this](Touch* touch, Event* evnt)
    {
        rocker->setVisible(false);
        rocker->setEnable(false);
    };
    
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
}
