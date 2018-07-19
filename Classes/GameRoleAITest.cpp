//
//  GameRoleAITest.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/17.
//

#include "GameRoleAITest.h"
#include "FightTestManager.h"
#include "GameRoleCmd.h"



GameRoleAITest* GameRoleAITest::_gInstance = nullptr;
bool GameRoleAITest::init()
{
//    addUpdate();
    srand((unsigned int)time(nullptr));
    CCRANDOM_0_1();
    return true;
}

void GameRoleAITest::start()
{
    addUpdate();
}


void GameRoleAITest::addUpdate()
{
//    schedule([this](float ft)
//    {
//        Vector<GameEnemyA*> enemyVector = FightTestManager::getInstance()->getEnemyVector();
//        for (auto enemy : enemyVector)
//        {
//            // 检测敌人  如果没有检测到  就让随机走路
//            _randomEnemy.pushBack(enemy);
//        }
//
//    }, 0.5, "checkUpdate");

//    Vector<GameEnemyA*> enemyVector = FightTestManager::getInstance()->getEnemyVector();
//    for (auto enemy : enemyVector)
//    {
//        // 检测敌人  如果没有检测到  就让随机走路
//        _randomEnemy.pushBack(enemy);
//    }
    
    
    schedule([this](float ft)
             {
                 for (auto enemy : _randomEnemy)
                 {
                     this->enemyRandomMove(enemy);
                 }
                 
             }, 3, "randomMove");
    
    
}



void GameRoleAITest::enemyRandomMove(GameEnemyA* enemy)
{
    float standRate = 0.5;
    float random = CCRANDOM_0_1();
    if (random < standRate) {
        // 站立
        enemy->handleInputCmd(GameRoleCmd::create(GameRoleCmd::Command::StandingCmd));
    }else{
        // 移动
        auto cmd = GameRoleCmd::create(GameRoleCmd::Command::WalkingCmd);
        if (enemy->getPositionX() < 568)
        {
            if (CCRANDOM_0_1() < 0.5)
            {
                cmd->setDirectionType(DirectionTypeDefine::RightType);
            }else{
                if (enemy->getPositionY() <200) {
                    cmd->setDirectionType(DirectionTypeDefine::RightUpType);
                }else{
                    cmd->setDirectionType(DirectionTypeDefine::RightDownType);
                }
            }
            
        }else
        {
            if (CCRANDOM_0_1() < 0.5)
            {
                cmd->setDirectionType(DirectionTypeDefine::LeftType);
            }else{
                if (enemy->getPositionY() < 220) {
                    cmd->setDirectionType(DirectionTypeDefine::LeftUpType);
                }else{
                    cmd->setDirectionType(DirectionTypeDefine::LeftDownType);
                }
            }
        }
        enemy->handleInputCmd(cmd);
    }
}


