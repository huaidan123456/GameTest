//
//  GameScene.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/4.
//

#ifndef GameScene_h
#define GameScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Hero.h"
#include "GameMap.h"

USING_NS_CC;


class GameScene:public Scene
{
public:
    CREATE_FUNC(GameScene);
    GameScene();
    ~GameScene();
    
    virtual bool init() override;
    virtual void onEnter() override;
    virtual void onExit() override;
    
    virtual void update(float delta) override;
    
    void loadSubview();
    
    
    
private:
    Hero* _hero;
    
    GameMap* gMap;
    Node* gameLayer;
    
    ui::Button* leftBtn;
    ui::Button* rightBtn;
    ui::Button* attackBtn;
    
};

#endif /* GameScene_h */
