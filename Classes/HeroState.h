//
//  HeroState.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/6.
//

#ifndef HeroState_h
#define HeroState_h

#include <stdio.h>

class HeroCmd;
class Hero;
class HeroState
{
public:
    virtual ~HeroState();
    
    /**
     状态入口 (当Hero进入此状态的时候，立即切换当前状态的行为)
     */
    virtual void enter(Hero* hero);
    
    /**
     *  状态出口
     */
    virtual void exit(Hero* hero);
    
    /**
    * 根据命令去切换英雄的状态
     @param hero 英雄指针
     @param cmd 命令
     @return 英雄状态
     */
    virtual HeroState* handleCommand(Hero* hero,HeroCmd* cmd);
    
    /**
     状态内部的更新（主要适用于复杂的状态改变，例如蓄力攻击等等）

     @param hero 英雄指针
     */
    virtual void update(Hero* hero);
    
};

#endif /* HeroState_h */
