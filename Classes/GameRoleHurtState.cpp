//
//  GameRoleHurtState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/9.
//

#include "GameRoleHurtState.h"
#include "GameRoleA.h"
#include "GameRoleCmd.h"
#include "GameRoleHurtState.h"
#include "GameRoleSkillState.h"


GameRoleHurtState::GameRoleHurtState()
{
    _stateID = RoleStateDefine::HurtingState;
}

GameRoleHurtState::~GameRoleHurtState()
{
    
}

void GameRoleHurtState::enter(GameRoleA* role)
{
    GameRoleState::enter(role);
    role->hurtAction();
}

void GameRoleHurtState::exit(GameRoleA* role)
{
    GameRoleState::exit(role);
    role->resetInitActionState();
}


GameRoleState* GameRoleHurtState::handleCommand(GameRoleA* role,GameRoleCmd* cmd)
{
    GameRoleState* state = nullptr;
    switch (cmd->getCommand()) {
        case GameRoleCmd::Command::StandingCmd:
        {
            break;
        }
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
            state = this;
            break;
        }
        case GameRoleCmd::Command::Skill1Cmd:
        {
//            state = new GameRoleSkillState();
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


void GameRoleHurtState::update(GameRoleA* role)
{
    GameRoleState::update(role);
}
