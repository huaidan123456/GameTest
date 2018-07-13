//
//  FightTestManager.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/11.
//

#ifndef FightTestManager_h
#define FightTestManager_h

#include <stdio.h>
#include "cocos2d.h"
#include "PublicDefine.h"
#include "GameEnemyA.h"

USING_NS_CC;

class FightTestManager:public Ref
{
public:
    CREATE_INSTANCE_FUNC(FightTestManager);
    DESTROY_INSTANCE_FUNC();
    
    bool init();
    
    void attackEnemyAs(Rect atkRect,int multiple);
    
    void addEnemy(GameEnemyA* enemy);
    
    const Vector<GameEnemyA*>& getEnemyVector() const;
    
protected:
    FightTestManager();
    ~FightTestManager();
    
    Vector<GameEnemyA*> _enemyVector;
    
};

#endif /* FightTestManager_h */
