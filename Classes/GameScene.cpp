//
//  GameScene.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/4.
//

#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "HeroCmd.h"


GameScene::GameScene()
{
    
}

GameScene::~GameScene()
{
    
}

bool GameScene::init()
{
    if (Scene::init()){
        
        loadSubview();
        return true;
    }
    
    return false;
}

void GameScene::onEnter()
{
    Scene::onEnter();
    scheduleUpdate();
}

void GameScene::onExit()
{
    Scene::onExit();
    unscheduleUpdate();
}

void GameScene::update(float delta)
{
    gMap->listenerMove(_hero);
}

void GameScene::loadSubview()
{
    gMap = GameMap::createWithMap("GameRes/map.jpg");
    this->addChild(gMap);
    
    
    gameLayer = CSLoader::createNode("Csb/GameLayer.csb");
    
    leftBtn = (ui::Button*)gameLayer->getChildByName("leftBtn");
    leftBtn->addTouchEventListener([this](Ref*ref,ui::Widget::TouchEventType type){
        switch (type) {
            case ui::Widget::TouchEventType::BEGAN:
                _hero->handleInputCmd(HeroCmd::create(HeroCmd::Command::MoveLeftCmd));
                break;
            case ui::Widget::TouchEventType::MOVED:
                break;
            case ui::Widget::TouchEventType::ENDED:
            case ui::Widget::TouchEventType::CANCELED:
                _hero->handleInputCmd(HeroCmd::create(HeroCmd::Command::StandingCmd));
                break;
                
            default:
                break;
        }
    });
    
    rightBtn = (ui::Button*)gameLayer->getChildByName("rightBtn");
    rightBtn->addTouchEventListener([this](Ref*ref,ui::Widget::TouchEventType type){
        switch (type) {
            case ui::Widget::TouchEventType::BEGAN:
                _hero->handleInputCmd(HeroCmd::create(HeroCmd::Command::MoveRightCmd));
                break;
            case ui::Widget::TouchEventType::MOVED:
                break;
            case ui::Widget::TouchEventType::ENDED:
            case ui::Widget::TouchEventType::CANCELED:
                _hero->handleInputCmd(HeroCmd::create(HeroCmd::Command::StandingCmd));
                break;
            default:
                break;
        }
    });
    
    attackBtn = (ui::Button*)gameLayer->getChildByName("aBtn");
    attackBtn->addClickEventListener([this](Ref* btn){
        _hero->handleInputCmd(HeroCmd::create(HeroCmd::Command::AttackCmd));
    });
    
    
    this->addChild(gameLayer,1);
    
    
    _hero = Hero::createWithRId(0);
    _hero->setPosition(300, 360);
    gMap->addEntity(_hero,2);
}
