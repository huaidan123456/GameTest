//
//  HeroMoveLeftState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/7.
//

#include "HeroMoveLeftState.h"
#include "Hero.h"
#include "HeroCmd.h"
#include "HeroAttackState.h"
#include "HeroStandingState.h"



HeroMoveLeftState::~HeroMoveLeftState()
{
    
}

void HeroMoveLeftState::enter(Hero *hero)
{
    hero->moveLeft();
}

void HeroMoveLeftState::exit(Hero *hero)
{
    
}

HeroState* HeroMoveLeftState::handleCommand(Hero *hero, HeroCmd *cmd)
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

void HeroMoveLeftState::update(Hero *hero)
{
    
}
