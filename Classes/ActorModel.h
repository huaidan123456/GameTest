//
//  ActorModel.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/13.
//

#ifndef ActorModel_h
#define ActorModel_h

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class ActorModel:public Ref
{
public:
    static ActorModel* createModel(int modelId);
    ActorModel();
    ~ActorModel();
    
protected:
    virtual bool initWithModelId(int modelId);
    
    
    //** 观察尺寸 *//
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(Size, _watchSize, WatchSize);
    //** 攻击尺寸 *//
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(Size, _attackSize, AttackSize);
    //** 受到攻击的尺寸 *//
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(Size, _hurtSize, HurtSize);
    
    
    //** 步行速度 *//
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(int, _walkSpeed, WalkSpeed);
    //** 跑步速度 *//
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(int, _runSpeed, RunSpeed);
    
    //** 最大的攻击段数 *//
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(int, _maxAttackStage, MaxAttackStage);
    
    
private:
    int _modelId = 0;
    
    
    
};

#endif /* ActorModel_h */
