//
//  GameEnemyA.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/11.
//

#ifndef GameEnemyA_h
#define GameEnemyA_h

#include <stdio.h>
#include "GameRoleA.h"
#include "DirectionDefine.h"


class GameEnemyA:public GameRoleA
{
public:
    static GameEnemyA* create(int roleId)
    {
        GameEnemyA *pRet = new(std::nothrow) GameEnemyA(roleId);
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
    
    GameEnemyA(int roleId = 20002)
    {
        _roleId = roleId;
    };
    
    virtual void doAttackEnemyAs(int multiple)override;
};

#endif /* GameEnemyA_h */
