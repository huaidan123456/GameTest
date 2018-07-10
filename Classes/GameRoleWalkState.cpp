//
//  GameRoleWalkState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/4.
//

#include "GameRoleWalkState.h"
#include "GameRoleA.h"
#include "GameRoleCmd.h"
#include "GameRoleStandState.h"
#include "GameRoleRunState.h"
#include "GameRoleAttackState.h"
#include "GameRoleHurtState.h"
#include "GameRoleSkillState.h"


GameRoleWalkState::GameRoleWalkState()
{
    _stateID = RoleStateDefine::WalkingState;
}

GameRoleWalkState::GameRoleWalkState(const DirectionTypeDefine& direction)
{
    _stateID = RoleStateDefine::WalkingState;
    _direction = direction;
}

GameRoleWalkState::~GameRoleWalkState()
{
    
}

void GameRoleWalkState::enter(GameRoleA* role)
{
    GameRoleState::enter(role);
    role->walkingAction(_direction);
    
}

void GameRoleWalkState::exit(GameRoleA* role)
{
    GameRoleState::exit(role);
}


GameRoleState* GameRoleWalkState::handleCommand(GameRoleA* role,GameRoleCmd* cmd)
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
            if (_direction != cmd->getDirectionType())
            {
                state = new GameRoleWalkState(cmd->getDirectionType());
            }
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


void GameRoleWalkState::update(GameRoleA* role)
{
    GameRoleState::update(role);
}


bool GameRoleWalkState::operator==(const GameRoleState &state)
{
    if (GameRoleState::operator==(state)) {
        return  (((GameRoleWalkState*)(&state))->_direction == _direction);
    }
    return false;
}
