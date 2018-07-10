//
//  GameRoleState.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/3.
//

#ifndef GameRoleState_h
#define GameRoleState_h

#include <stdio.h>
#include "RoleStateDefine.h"

class GameRoleCmd;
class GameRoleA;

class GameRoleState
{
public:
    GameRoleState();
    virtual ~GameRoleState();
    
    /**
     状态入口 (当Hero进入此状态的时候，立即切换当前状态的行为)
     */
    virtual void enter(GameRoleA* role);
    
    /**
     *  状态出口
     */
    virtual void exit(GameRoleA* role);
    /**
     * 根据命令去切换英雄的状态
     @param hero 英雄指针
     @param cmd 命令
     @return 英雄状态
     */
    virtual GameRoleState* handleCommand(GameRoleA* role,GameRoleCmd* cmd);
    
    /**
     状态内部的更新（主要适用于复杂的状态改变，例如蓄力攻击等等）
     
     @param hero 英雄指针
     */
    virtual void update(GameRoleA* role);
    
    
    virtual bool operator == (const GameRoleState& state);
    
    virtual bool operator != (const GameRoleState& state);

    
    
protected:
    /** 状态持续时间 */
    float _stateDuration = 0;
    
    /** 状态Id */
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(int, _stateID, StateID);
    
    
    
};

#endif /* GameRoleState_h */
