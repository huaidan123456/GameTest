//
//  GameRoleAttackState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/5.
//

#include "GameRoleAttackState.h"
#include "GameRoleA.h"
#include "GameRoleCmd.h"
#include "GameRoleStandState.h"
#include "GameRoleWalkState.h"
#include "GameRoleRunState.h"
#include "GameRoleHurtState.h"
#include "GameRoleSkillState.h"


GameRoleAttackState::GameRoleAttackState()
{
    _stateID = RoleStateDefine::AttackState;
}

GameRoleAttackState::~GameRoleAttackState()
{
    
}

void GameRoleAttackState::enter(GameRoleA* role)
{
    GameRoleState::enter(role);
    role->attackAction();
    
}

void GameRoleAttackState::exit(GameRoleA* role)
{
    GameRoleState::exit(role);
    role->resetInitActionState();
}


GameRoleState* GameRoleAttackState::handleCommand(GameRoleA* role,GameRoleCmd* cmd)
{
    GameRoleState* state = nullptr;
    switch (cmd->getCommand()) {
        case GameRoleCmd::Command::StandingCmd:
        {
            state = new GameRoleStandState();
            break;
        }
        case GameRoleCmd::Command::WalkingCmd:
        {
            state = new GameRoleWalkState(cmd->getDirectionType());
            break;
        }
        case GameRoleCmd::Command::RunningCmd:
        {
            state = new GameRoleRunState(cmd->getDirectionType());
            break;
        }
        case GameRoleCmd::Command::AttackCmd:
        {
            state = this;
            break;
        }
        case GameRoleCmd::Command::HurtingCmd:
        {
            state = new GameRoleHurtState();
            break;
        }
        case GameRoleCmd::Command::Skill1Cmd:
        {
            state = new GameRoleSkillState();
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


void GameRoleAttackState::update(GameRoleA* role)
{
    GameRoleState::update(role);
}
