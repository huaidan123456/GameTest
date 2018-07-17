//
//  GameEnemyA.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/11.
//

#ifndef GameEnemyA_h
#define GameEnemyA_h

#include <stdio.h>
#include "EntityTestBase.h"
#include "DirectionDefine.h"


class GameEnemyA:public EntityTestBase
{
public:
    CREATE_FUNC(GameEnemyA);
    static GameEnemyA* create(int roleId)
    {
        GameEnemyA *pRet = new(std::nothrow) GameEnemyA(roleId);
        if (pRet && pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
    
    GameEnemyA(int roleId = 10032);
    virtual ~GameEnemyA();
    
    virtual bool init() override;
    
    
public:
    
    /**
     *  动作
     */
    
    // 站立等待动作
    void standingWaitAction();
    // 步行动作
    void walkingAction(DirectionTypeDefine directionType);
    // 攻击动作
    void attackAction();
    // 受攻击动作
    void hurtAction();
    
    
    
    
    /**
     *  获取攻击范围
     */
    virtual Rect getRoleAttackRect();
    
    /**
     *  获取被攻击范围
     */
    virtual Rect getRoleHurtRect();
    
    /**
      获取视野范围
     */
    virtual Rect getRoleWatchRect();
    
    
    
protected:
    void initRole();
    
    // 停止所有活动动作
    void stopAllActionAnimation();
    
    
    
    // 设置角色是否反转
    void setupRoleFlippedX(bool isFlipped);
    bool isRoleFlippedX();
    
    
private:
    Sprite* _pRole = nullptr;
    Sprite* _pShadow = nullptr;
    Sprite* _pHurt = nullptr;
    Node* _pAtkEffectNode = nullptr;
    Node* _pSkillEffectNode = nullptr;
    
    //** 方向 *//
    DirectionTypeDefine _direction;
    //** 当前速度 *//
    float _nowSpeed;
    
    //** 攻击阶段 *//
    int _attackStage = 0;
    //** 是否可以更改攻击状态 *//
    bool _changeAttackEnable = true;
    
    //** 攻击尺寸 *//
    Size _attackSize;
    
    //** 观察尺寸 *//
    Size _watchSize;
    
    int _roleId = 10032;
    float _speedWalk;
    float _speedRun;
    
};

#endif /* GameEnemyA_h */
