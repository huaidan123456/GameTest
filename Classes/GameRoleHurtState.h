//
//  GameRoleHurtState.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/9.
//

#ifndef GameRoleHurtState_h
#define GameRoleHurtState_h

#include <stdio.h>
#include "GameRoleState.h"

class GameRoleHurtState:public GameRoleState
{
public:
    GameRoleHurtState();
    virtual ~GameRoleHurtState();
    
    /**
     状态入口 (当Hero进入此状态的时候，立即切换当前状态的行为)
     */
    virtual void enter(GameRoleA* role) override;
    
    /**
     *  状态出口
     */
    virtual void exit(GameRoleA* role) override;
    /**
     * 根据命令去切换英雄的状态
     @param hero 英雄指针
     @param cmd 命令
     @return 英雄状态
     */
    virtual GameRoleState* handleCommand(GameRoleA* role,GameRoleCmd* cmd) override;
    
    /**
     状态内部的更新（主要适用于复杂的状态改变，例如蓄力攻击等等）
     
     @param hero 英雄指针
     */
    virtual void update(GameRoleA* role) override;
    
    
};


#endif /* GameRoleHurtState_h */
