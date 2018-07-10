//
//  HeroAttackState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/7.
//

#include "HeroAttackState.h"
#include "Hero.h"
#include "HeroCmd.h"
#include "HeroMoveRightState.h"
#include "HeroMoveLeftState.h"
#include "HeroStandingState.h"



HeroAttackState::~HeroAttackState()
{
    
}

void HeroAttackState::enter(Hero *hero)
{
    CCLOG("进入 %d 攻击状态",_attackStage);
    hero->attack(_attackStage);
}

void HeroAttackState::exit(Hero *hero)
{
    CCLOG("离开攻击状态");
    hero->handleInputCmd(HeroCmd::create(HeroCmd::Command::StandingCmd));
}

HeroState* HeroAttackState::handleCommand(Hero *hero, HeroCmd *cmd)
{
    HeroState* state = nullptr;
    switch (cmd->getCommand()) {
        case HeroCmd::Command::StandingCmd:
        {
            state = new HeroStandingState();
            break;
        }
        case HeroCmd::Command::MoveLeftCmd:
        {
//            state = new HeroMoveRightState();
            break;
        }
        case HeroCmd::Command::MoveRightCmd:
        {
//            state = new HeroMoveRightState();
            break;
        }
        case HeroCmd::Command::AttackCmd:
        {
            if (_attackStage == 1 && _stageTime >= 0.8 && _stageTime < 1.5 ) {
                _stageTime = 0;
                _attackStage = 2;
                state = this;
            }

            break;
        }
            
        default:
            break;
            
    }
    return state;
}

void HeroAttackState::update(Hero *hero)
{
    _stageTime+= 0.1f;
    float mt = _attackStage == 1 ? 1.5 : 1;
    
    if (_stageTime >= mt){
        exit(hero);
    }
    
}
