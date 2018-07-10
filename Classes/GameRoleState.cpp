//
//  GameRoleState.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/3.
//

#include "GameRoleState.h"

GameRoleState::GameRoleState()
{
    _stateID = RoleStateDefine::NoneState;
}

GameRoleState::~GameRoleState()
{
    
}

void GameRoleState::enter(GameRoleA* role)
{
    _stateDuration = 0;
}


void GameRoleState::exit(GameRoleA* role)
{
    
}


GameRoleState* GameRoleState::handleCommand(GameRoleA* role,GameRoleCmd* cmd)
{
    return nullptr;
}


void GameRoleState::update(GameRoleA* role)
{
    _stateDuration += 0.1f;
}


bool GameRoleState::operator == (const GameRoleState& state)
{
    return _stateID == state._stateID;
}

bool GameRoleState::operator != (const GameRoleState& state)
{
    return !(*this == state);
}
