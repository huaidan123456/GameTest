//
//  GameRoleRunState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/4.
//

#include "GameRoleRunState.h"
#include "GameRoleA.h"
#include "GameRoleCmd.h"
#include "GameRoleStandState.h"
#include "GameRoleWalkState.h"
#include "GameRoleAttackState.h"
#include "GameRoleHurtState.h"
#include "GameRoleSkillState.h"


GameRoleRunState::GameRoleRunState()
{
    _stateID = RoleStateDefine::RunningState;
}

GameRoleRunState::GameRoleRunState(const DirectionTypeDefine& direction)
{
    _stateID = RoleStateDefine::RunningState;
    _direction = direction;
}

GameRoleRunState::~GameRoleRunState()
{
    
}

void GameRoleRunState::enter(GameRoleA* role)
{
    GameRoleState::enter(role);
    role->runningAction(_direction);
}

void GameRoleRunState::exit(GameRoleA* role)
{
    GameRoleState::exit(role);
}


GameRoleState* GameRoleRunState::handleCommand(GameRoleA* role,GameRoleCmd* cmd)
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
            if (_direction != cmd->getDirectionType())
            {
                state = new GameRoleRunState(cmd->getDirectionType());
            }
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


void GameRoleRunState::update(GameRoleA* role)
{
    GameRoleState::update(role);
}


bool GameRoleRunState::operator==(const GameRoleState &state)
{
    if (GameRoleState::operator==(state)) {
        return  (((GameRoleRunState*)(&state))->_direction == _direction);
    }
    return false;
}
