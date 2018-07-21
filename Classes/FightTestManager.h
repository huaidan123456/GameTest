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
#include "GameRoleA.h"

USING_NS_CC;

class FightTestManager:public Ref
{
public:
    CREATE_INSTANCE_FUNC(FightTestManager);
    DESTROY_INSTANCE_FUNC();
    
    bool init();
    
    void attackEnemyAs(Rect atkRect,int atk);
    
    void attackRoleAs(Rect atkRect,int atk);
    
    void addRole(GameRoleA* enemy);
    
    const Vector<GameRoleA*>& getRoleVector() const;
    
    void addEnemy(GameEnemyA* enemy);
    
    const Vector<GameEnemyA*>& getEnemyVector() const;
    
protected:
    FightTestManager();
    ~FightTestManager();
    
    Vector<GameEnemyA*> _enemyVector;
    Vector<GameRoleA*> _roleVector;
    
};

#endif /* FightTestManager_h */
