//
//  GameRoleDeathState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/19.
//

#include "GameRoleDeathState.h"
#include "GameRoleA.h"
#include "GameRoleCmd.h"


GameRoleDeathState::GameRoleDeathState()
{
    _stateID = RoleStateDefine::StandingState;
}

GameRoleDeathState::~GameRoleDeathState()
{
    
}

void GameRoleDeathState::enter(GameRoleA* role)
{
    GameRoleState::enter(role);
    role->deathAction();
    
}

void GameRoleDeathState::exit(GameRoleA* role)
{
    GameRoleState::exit(role);
}


GameRoleState* GameRoleDeathState::handleCommand(GameRoleA* role,GameRoleCmd* cmd)
{
    GameRoleState* state = nullptr;
    switch (cmd->getCommand()) {
        case GameRoleCmd::Command::WalkingCmd:
        {
            
            break;
        }
        case GameRoleCmd::Command::RunningCmd:
        {
            
            break;
        }
        case GameRoleCmd::Command::AttackCmd:
        {
            
            break;
        }
        case GameRoleCmd::Command::HurtingCmd:
        {
            
            break;
        }
        case GameRoleCmd::Command::Skill1Cmd:
        {
            
            break;
        }
        case GameRoleCmd::Command::Skill2Cmd:
        {
            
            break;
        }
        case GameRoleCmd::Command::Skill3Cmd:
        {
            
            break;
        }
        case GameRoleCmd::Command::Skill4Cmd:
        {
            
            break;
        }
        case GameRoleCmd::Command::Skill5Cmd:
        {
            
            break;
        }
        default:
            break;
    }
    
    return state;
}


void GameRoleDeathState::update(GameRoleA* role)
{
    GameRoleState::update(role);
}
