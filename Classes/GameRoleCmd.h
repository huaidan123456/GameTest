//
//  GameRoleCmd.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/3.
//

#ifndef GameRoleCmd_h
#define GameRoleCmd_h

#include <stdio.h>
#include "cocos2d.h"
#include "DirectionDefine.h"

USING_NS_CC;


class GameRoleCmd:public Ref
{
public:
    enum class Command
    {
        StandingCmd,  // 站立
        WalkingCmd,
        RunningCmd,
        HurtingCmd,
        AttackCmd,
        Skill1Cmd,
        Skill2Cmd,
        Skill3Cmd,
        Skill4Cmd,
        Skill5Cmd,
    };
    
    
public:
    static GameRoleCmd* create(GameRoleCmd::Command cmd = GameRoleCmd::Command::StandingCmd);
    
    virtual ~GameRoleCmd();
    
    
protected:
    CC_SYNTHESIZE_PASS_BY_REF(Command, _command, Command);
    CC_SYNTHESIZE_PASS_BY_REF(DirectionTypeDefine,_direction,DirectionType);
    
};

#endif /* GameRoleCmd_h */
