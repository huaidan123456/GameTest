//
//  ActorModel.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/13.
//

#include "ActorModel.h"
#include "ActorModelUtil.h"

ActorModel::ActorModel(){}
ActorModel::~ActorModel(){}

ActorModel* ActorModel::createModel(int modelId)
{
    ActorModel *pModel = new(std::nothrow) ActorModel();
    if (pModel && pModel->initWithModelId(modelId)) {
        pModel->autorelease();
        return pModel;
    }else{
        delete pModel;
        pModel = nullptr;
        return nullptr;
    }
}

bool ActorModel::initWithModelId(int modelId)
{
    // TODO: todo:判断此Id是否存在
    // 如果Id存在的话。
    // 应该数据表里面获取用户的相关信息
    
    _modelId = modelId;
    
    auto modelUtil = ActorModelUtil::getInstance();
    _watchSize = modelUtil->getActorWatchSize(modelId);
    _attackSize = modelUtil->getActorAttackSize(modelId);
    _hurtSize = modelUtil->getActorHurtSize(modelId);
    
    // TODO: todo: 步行速度  和 跑步速度  攻击最大段数
    _walkSpeed = 30;
    _runSpeed = 80;
    _maxAttackStage = 5;
    
    return true;
}





