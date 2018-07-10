//
//  TestWelcomeScene.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/29.
//

#ifndef TestWelcomeScene_h
#define TestWelcomeScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;

USING_NS_CC;

class TestWelcomeScene:public Scene
{
public:
    CREATE_FUNC(TestWelcomeScene);
    
    virtual bool init()override;
    
};

#endif /* TestWelcomeScene_h */
