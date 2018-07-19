//
//  GameEnemyA.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/11.
//

#include "GameEnemyA.h"

#include "FightTestManager.h"


void GameEnemyA::doAttackEnemyAs(int multiple)
{
    FightTestManager::getInstance()->attackRoleAs(getRoleAttackRect(), multiple);
}
