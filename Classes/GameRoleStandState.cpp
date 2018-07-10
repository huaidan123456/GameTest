//
//  GameRoleStandState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/3.
//

#include "GameRoleStandState.h"
#include "GameRoleA.h"
#include "GameRoleCmd.h"
#include "GameRoleWalkState.h"
#include "GameRoleRunState.h"
#include "GameRoleAttackState.h"
#include "GameRoleHurtState.h"
#include "GameRoleSkillState.h"


GameRoleStandState::GameRoleStandState()
{
    _stateID = RoleStateDefine::StandingState;
}

GameRoleStandState::~GameRoleStandState()
{
    
}

void GameRoleStandState::enter(GameRoleA* role)
{
    GameRoleState::enter(role);
    role->standingWaitAction();
    
}

void GameRoleStandState::exit(GameRoleA* role)
{
    GameRoleState::exit(role);
}


GameRoleState* GameRoleStandState::handleCommand(GameRoleA* role,GameRoleCmd* cmd)
{
    GameRoleState* state = nullptr;
    switch (cmd->getCommand()) {
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
            state = new GameRoleAttackState();
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


void GameRoleStandState::update(GameRoleA* role)
{
    GameRoleState::update(role);
}
