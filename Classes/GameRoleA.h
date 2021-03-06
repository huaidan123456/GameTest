//
//  GameRoleA.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/3.
//

#ifndef GameRoleA_h
#define GameRoleA_h

#include <stdio.h>
#include "EntityTestBase.h"
#include "DirectionDefine.h"
#include "BloodStripView.h"


class GameRoleCmd;
class GameRoleState;
class BloodStripView;
class GameRoleA:public EntityTestBase
{
public:
    CREATE_FUNC(GameRoleA);
    static GameRoleA* create(int roleId)
    {
        GameRoleA *pRet = new(std::nothrow) GameRoleA(roleId);
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
    GameRoleA(int roleId = 20002);
    virtual ~GameRoleA();
    
    virtual bool init() override;
    
    
public:
    
    /**
     接收命令的方法
     @param cmd 命令
     */
    void handleInputCmd(GameRoleCmd* cmd);
    
    
    
    /**
     重置动作状态
     */
    void resetInitActionState();
    
    
    /**
     *  获取攻击范围
     */
    virtual Rect getRoleAttackRect();
    
    /**
     *  获取技能攻击范围
     */
    virtual Rect getRoleSkillAtkRect();
    
    /**
     *  获取被攻击范围
     */
    virtual Rect getRoleHurtRect();
    
    
    /**
     *  获取角色的攻击范围
     */
    virtual Rect getRoleWatchRect();
    
    
    
    /**
     *  执行攻击敌人函数
     */
    virtual void doAttackEnemyAs(int atk);
    
    /**
     掉血操作
     */
    virtual void doLoseHp(int loseNum);
    
    

    /**
     *  动作
     */
    // 站立等待动作
    void standingWaitAction();
    // 站立懒散动作
    void standingIdleAction();
    // 步行动作
    void walkingAction(DirectionTypeDefine directionType);
    // 奔跑动作
    void runningAction(DirectionTypeDefine directionType);
    // 攻击动作
    void attackAction();
    // 受攻击动作
    void hurtAction();
    
    void skill1Action();
    void skill2Action();
    void skill3Action();
    void skill4Action();
    void skill5Action();
    void deathAction();
    
    
protected:
    void initRole();
    
    // 停止所有活动动作
    void stopAllActionAnimation();
    
    // 移动
    void listenerMove(float time);
    
    // 恢复最初攻击阶段
    void resetAttackStage();
    
    
    // 设置角色是否反转
    void setupRoleFlippedX(bool isFlipped);
    bool isRoleFlippedX();
    
    bool isRoleDirectionRight(){ return !isRoleFlippedX();};
    
    // 添加攻击效果Sprite*
    void addAttackEffect(Sprite* sp, int zOrder = 0);
    void removeAttackEffect(const std::string& name);
    
    // 添加技能效果Sprite*
    void addSkillEffect(Sprite* sp, int zOrder = 0);
    void removeSkillEffect(const std::string& name);
    
protected:
    //** 动作状态 *//
    CC_SYNTHESIZE_READONLY(GameRoleState*, _actionState, ActionState);
    
    //** 方向状态是否可用 *//
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(bool, _directionEnable, DirectionEnable);
    
    
    
protected:
    Sprite* _pRole = nullptr;
    Sprite* _pShadow = nullptr;
    Sprite* _pHurt = nullptr;
    Node* _pAtkEffectNode = nullptr;
    Node* _pSkillEffectNode = nullptr;
    BloodStripView* _pBloodView = nullptr;
    
    
    
    DirectionTypeDefine _direction;
    //** 当前速度 *//
    float _nowSpeed;
    int _hp;
    //** 攻击阶段 *//
    int _attackStage = 0;
    //** 是否可以更改攻击状态 *//
    bool _changeAttackEnable = true;
    
    //** 攻击尺寸 *//
    Size _attackSize;
    //** 技能尺寸 *//
    Size _skillSize;
    //** 受到攻击的尺寸 *//
    Size _hurtSize;
    //** 视野尺寸 *//
    Size _watchSize;
    
    
    
    int _roleId = 20002;
    float _speedWalk;
    float _speedRun;
    
    //** 总血量 *//
    int _hpTotal;
    //** 基础攻击力 *//
    int _atkBase;
    
    
    
};

#endif /* GameRoleA_h */
