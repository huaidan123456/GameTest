//
//  FightTestManager.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/11.
//

#include "FightTestManager.h"
#include "GameRoleCmd.h"


FightTestManager* FightTestManager::_gInstance = nullptr;

FightTestManager::FightTestManager()
{
    
}

FightTestManager::~FightTestManager()
{
    
}

bool FightTestManager::init()
{
    return true;
}

void FightTestManager::addEnemy(GameEnemyA* enemy)
{
    _enemyVector.pushBack(enemy);
}

void FightTestManager::addRole(GameRoleA *enemy)
{
    _roleVector.pushBack(enemy);
}


const Vector<GameEnemyA*>& FightTestManager::getEnemyVector() const
{
    return _enemyVector;
}

const Vector<GameRoleA*>& FightTestManager::getRoleVector()const
{
    return _roleVector;
}


void FightTestManager::attackEnemyAs(Rect atkRect,int atk)
{
    for (auto enemy : _enemyVector) {
        auto hurtRect = enemy->getRoleHurtRect();
//        CCLOG("atkRect = (%f,%f,%f,%f) -- hurtRect = (%f,%f,%f,%f)",atkRect.origin.x,atkRect.origin.y,atkRect.size.width,atkRect.size.height,hurtRect.origin.x,hurtRect.origin.y,hurtRect.size.width,hurtRect.size.height);
        
        if (atkRect.intersectsRect(hurtRect))
        {
            enemy->handleInputCmd(GameRoleCmd::create(GameRoleCmd::Command::HurtingCmd));
            enemy->doLoseHp(atk);
        }
    }
}

void FightTestManager::attackRoleAs(cocos2d::Rect atkRect, int atk)
{
    for (auto role : _roleVector) {
        auto hurtRect = role->getRoleHurtRect();
        if (atkRect.intersectsRect(hurtRect)) {
            role->handleInputCmd(GameRoleCmd::create(GameRoleCmd::Command::HurtingCmd));
        }
    }
}





