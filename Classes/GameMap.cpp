//
//  GameMap.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/11.
//

#include "GameMap.h"

GameMap* GameMap::createWithMap(const std::string &filename)
{
    GameMap* pMap = new (std::nothrow) GameMap();
    if (pMap && pMap->initMap(filename)) {
        pMap->autorelease();
        return pMap;
    }else{
        CC_SAFE_DELETE(pMap);
        return nullptr;
    }
}


bool GameMap::initMap(const std::string &filename)
{
    if (Layer::init()) {
        _pMap = Sprite::create(filename);
        _pMap->setPosition(0, 0);
        _pMap->setAnchorPoint(Vec2(0, 0));
        this->addChild(_pMap);
        return true;
    }
    return false;
}

void GameMap::listenerMove(cocos2d::Node *hero)
{
    Size winSize = Director::getInstance()->getWinSize();
    Size mapSize = _pMap->getContentSize();
    Point actualPosition = Vec2(hero->getPositionX(), hero->getPositionY());
    actualPosition.x = MIN(MAX(actualPosition.x, winSize.width/2), mapSize.width-winSize.width/2);
    actualPosition.y = MIN(MAX(actualPosition.y, winSize.height/2), mapSize.height-winSize.height/2);
    
    Point mapPosition = Vec2(winSize.width/2 - actualPosition.x, winSize.height/2 - actualPosition.y);
    
    _pMap->setPosition(mapPosition);
}
