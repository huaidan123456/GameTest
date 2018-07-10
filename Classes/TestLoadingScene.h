//
//  TestLoadingScene.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/29.
//

#ifndef TestLoadingScene_h
#define TestLoadingScene_h

#include <stdio.h>
#include "ALSceneExtension.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;

class TestLoadingScene:public ALSceneExtension
{
public:
    CREATE_FUNC(TestLoadingScene);
    
    virtual ~TestLoadingScene();
    
    virtual void onLoadLoading() override;
    virtual void onLoadResources()override;
    virtual void onLoadResourcesProgress(float percent)override;
    virtual void onLoadResourcesCompleted()override;
    virtual void onLoadScene()override;
    
    
    
private:
    Text* showText;
    
    Sprite* hero;
    
};

#endif /* TestLoadingScene_h */
