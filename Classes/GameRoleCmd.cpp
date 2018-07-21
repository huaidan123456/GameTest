//
//  GameRoleCmd.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/3.
//

#include "GameRoleCmd.h"


GameRoleCmd::~GameRoleCmd()
{
    
}

GameRoleCmd* GameRoleCmd::create(GameRoleCmd::Command cmd)
{
    GameRoleCmd * ret = new (std::nothrow) GameRoleCmd();
    if (ret)
    {
        ret->setCommand(cmd);
        ret->setDirectionType(DirectionTypeDefine::NoneType);
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}
