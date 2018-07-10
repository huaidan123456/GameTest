//
//  GameRoleSkillState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/9.
//

#include "GameRoleSkillState.h"
#include "GameRoleA.h"
#include "GameRoleCmd.h"
//#include "GameRoleWalkState.h"
//#include "GameRoleRunState.h"
//#include "GameRoleAttackState.h"
#include "GameRoleHurtState.h"



GameRoleSkillState::GameRoleSkillState()
{
    _stateID = RoleStateDefine::SkillState;
}

GameRoleSkillState::~GameRoleSkillState()
{
    
}

void GameRoleSkillState::enter(GameRoleA* role)
{
    GameRoleState::enter(role);
    role->skill1Action();
}

void GameRoleSkillState::exit(GameRoleA* role)
{
    GameRoleState::exit(role);
    role->resetInitActionState();
}


GameRoleState* GameRoleSkillState::handleCommand(GameRoleA* role,GameRoleCmd* cmd)
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
            state = new GameRoleHurtState();
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


void GameRoleSkillState::update(GameRoleA* role)
{
    GameRoleState::update(role);
}

