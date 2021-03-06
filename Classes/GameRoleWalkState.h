//
//  GameRoleWalkState.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/4.
//

#ifndef GameRoleWalkState_h
#define GameRoleWalkState_h

#include <stdio.h>
#include "GameRoleState.h"
#include "DirectionDefine.h"

class GameRoleWalkState:public GameRoleState
{
public:
    GameRoleWalkState();
    GameRoleWalkState(const DirectionTypeDefine& direction);
    virtual ~GameRoleWalkState();
    
    
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
    
    
    virtual bool operator == (const GameRoleState& state) override;
    
protected:

    DirectionTypeDefine _direction;
    
    
};

#endif /* GameRoleWalkState_h */
