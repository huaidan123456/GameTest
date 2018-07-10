//
//  GameMap.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/11.
//

#ifndef GameMap_h
#define GameMap_h

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;


class GameMap:public Layer
{
public:
    static GameMap* createWithMap(const std::string& filename);
    
    virtual bool initMap(const std::string& filename);
    
    virtual void listenerMove(Node* hero);
    
    virtual void addEntity(Node* hero,int localZOrder = 0){_pMap->addChild(hero, localZOrder);};
private:
    Sprite* _pMap;
};

#endif /* GameMap_h */
