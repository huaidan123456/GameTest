//
//  TestRockerScene.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/22.
//

#ifndef TestRockerScene_h
#define TestRockerScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameRocker.h"
USING_NS_CC;

using namespace cocos2d::ui;


class TestRockerScene:public Scene
{
public:
    CREATE_FUNC(TestRockerScene);
    
    virtual bool init() override;
    
    virtual void update(float delta) override;
    
    
    void loadSubview();

    Text* showText;
    GameRocker* rocker;

    
};
#endif /* TestRockerScene_h */
