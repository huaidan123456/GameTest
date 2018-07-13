//
//  ActorBase.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/13.
//

#ifndef ActorBase_h
#define ActorBase_h

#include <stdio.h>
#include "EntityBase.h"
#include "DirectionDefine.h"


class ActorModel;
class ActorBase:public EntityBase
{
public:
    virtual ~ActorBase();
   
    
public:
    /**
     *  获取观察范围
     */
    virtual Rect getWatchRect();
    
    /**
     *  获取攻击范围
     */
    virtual Rect getAttackRect();
    
    // TODO: 技能相关的还没有想好呢
//    /**
//     *  获取技能攻击范围
//     */
//    virtual Rect getSkillAtkRect();
    
    /**
     *  获取被攻击范围
     */
    virtual Rect getHurtRect();
    
    
public:
    // 动作
    // 站立等待动作
    virtual void standingWaitAction();
    // 站立懒散动作
    virtual void standingIdleAction();
    // 步行动作
    virtual void walkingAction(DirectionTypeDefine directionType);
    // 奔跑动作
    virtual void runningAction(DirectionTypeDefine directionType);
    // 攻击动作
    virtual void attackAction();
    // 受攻击动作
    virtual void hurtAction();
    // 技能动作
    virtual void skillAction();
    
protected:
    Sprite* _pSprite = nullptr;
    //** 影子 *//
    Sprite* _pShadow = nullptr;
    //** 受伤效果 *//
    Sprite* _pHurtEffect = nullptr;
    //** 攻击效果 *//
    Node* _pAtkEffectNode = nullptr;
    //** 技能效果 *//
    Node* _pSkillEffectNode = nullptr;
    
    //** 当前方向 *//
    DirectionTypeDefine _direction;
    //** 当前速度 *//
    float _speed = 0;
    //** 当前攻击阶段 *//
    int _attackStage = 0;
    //** 是否可以更改攻击状态 *//
    bool _changeAttackEnable = true;
    
    
    ActorModel* _model = nullptr;
    
//    //** 观察尺寸 *//
//    Size _watchSize;
//    //** 攻击尺寸 *//
//    Size _attackSize;
//    //** 技能尺寸 *//
//    Size _skillSize;
//    //** 受到攻击的尺寸 *//
//    Size _hurtSize;
    
};

#endif /* ActorBase_h */
