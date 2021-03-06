//
//  HeroStandingState.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/6.
//

#ifndef HeroStandingState_h
#define HeroStandingState_h

#include <stdio.h>
#include "HeroState.h"


class HeroStandingState:public HeroState
{
public:
    virtual ~HeroStandingState();
    
    /**
     状态入口 (当Hero进入此状态的时候，立即切换当前状态的行为)
     */
    virtual void enter(Hero* hero) override;
    
    /**
     *  状态出口
     */
    virtual void exit(Hero* hero) override;
    
    /**
     * 根据命令去切换英雄的状态
     @param hero 英雄指针
     @param cmd 命令
     @return 英雄状态
     */
    virtual HeroState* handleCommand(Hero* hero,HeroCmd* cmd) override;
    
    /**
     状态内部的更新（主要适用于复杂的状态改变，例如蓄力攻击等等）
     
     @param hero 英雄指针
     */
    virtual void update(Hero* hero) override;
    
    
private:
    float _idleTime = 0.f;
    int _idleState = 0;
    
    
};

#endif /* HeroStandingState_h */
