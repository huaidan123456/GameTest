//
//  HeroCmd.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/7.
//

#ifndef HeroCmd_h
#define HeroCmd_h

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;


class HeroCmd:public Ref
{
public:
    enum class Command
    {
        StandingCmd = 1,  // 站立
        MoveLeftCmd,
        MoveRightCmd,
        AttackCmd,
    };
    
public:
    static HeroCmd* create(HeroCmd::Command cmd = HeroCmd::Command::StandingCmd);
    
    virtual ~HeroCmd();
    
    
protected:
    CC_SYNTHESIZE_PASS_BY_REF(Command, _command, Command);
    
};

#endif /* HeroCmd_h */
