//
//  HeroMoveRightState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/7.
//

#include "HeroMoveRightState.h"
#include "Hero.h"
#include "HeroCmd.h"
#include "HeroAttackState.h"
#include "HeroStandingState.h"


HeroMoveRightState::~HeroMoveRightState()
{
    
}

void HeroMoveRightState::enter(Hero *hero)
{
    hero->moveRight();
}

void HeroMoveRightState::exit(Hero *hero)
{
    
}

HeroState* HeroMoveRightState::handleCommand(Hero *hero, HeroCmd *cmd)
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
            break;
        }
        case HeroCmd::Command::MoveRightCmd:
        {
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

void HeroMoveRightState::update(Hero *hero)
{
    
}
