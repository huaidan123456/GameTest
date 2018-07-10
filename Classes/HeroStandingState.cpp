//
//  HeroStandingState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/6.
//

#include "HeroStandingState.h"
#include "Hero.h"
#include "HeroCmd.h"
#include "HeroMoveLeftState.h"
#include "HeroMoveRightState.h"
#include "HeroAttackState.h"



HeroStandingState::~HeroStandingState()
{
    
}

void HeroStandingState::enter(Hero *hero)
{
    _idleTime = 0;
    _idleState = 0;
    hero->standingIdle();
}

void HeroStandingState::exit(Hero *hero)
{
    
}

HeroState* HeroStandingState::handleCommand(Hero *hero, HeroCmd *cmd)
{
    HeroState* state = nullptr;
    switch (cmd->getCommand())
    {
        case HeroCmd::Command::MoveLeftCmd:
        {
            state = new HeroMoveLeftState();
            break;
        }
        case HeroCmd::Command::MoveRightCmd:
        {
            state = new HeroMoveRightState();
            break;
        }
        case HeroCmd::Command::AttackCmd:
        {
            state = new HeroAttackState();
            break;
        }
        default:
            break;
    }
    return state;
}

void HeroStandingState::update(Hero *hero)
{
    _idleTime+= 0.1;
    
    if (_idleTime >= 5.f && _idleState != 1) {
        hero->standingIdle2();
        _idleState = 1;
    }

}


