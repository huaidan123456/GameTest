//
//  GDMainGameScene.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/29.
//

#ifndef GDMainGameScene_h
#define GDMainGameScene_h

#include <stdio.h>
#include "ALSceneExtension.h"

class GameRocker;
class GameRoleA;
class GDMainGameScene:public ALSceneExtension
{
public:
    CREATE_FUNC(GDMainGameScene);
    
    virtual ~GDMainGameScene();
    
    virtual void onLoadLoading() override;
    virtual void onLoadResources()override;
    virtual void onLoadResourcesProgress(float percent)override;
    virtual void onLoadResourcesCompleted()override;
    virtual void onLoadScene() override;
    
    
    
    virtual void update(float delta) override;
    
    
    
    
    void loadGameScene();
    
    
    
protected:
    
    /**
     *  刷新英雄位置状态
     */
    void refreshHeroDirectionState();
    
    
    
private:
    //** 虚拟摇杆 *//
    GameRocker* pRocker;
    
    GameRoleA* _pHero;
    
    
    
    
    
    
    
};

#endif /* GDMainGameScene_h */
