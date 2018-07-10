//
//  HeroCmd.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/7.
//

#include "HeroCmd.h"


HeroCmd::~HeroCmd()
{
    CCLOG("~HeroCmd()");
}

HeroCmd* HeroCmd::create(HeroCmd::Command cmd)
{
    HeroCmd * ret = new (std::nothrow) HeroCmd();
    if (ret)
    {
        ret->setCommand(cmd);
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

