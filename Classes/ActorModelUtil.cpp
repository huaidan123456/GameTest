//
//  ActorModelUtil.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/13.
//

#include "ActorModelUtil.h"
#include "CsvConfigDefine.h"
#include "ALCsvUtil.h"



ActorModelUtil* ActorModelUtil::_instance;

ActorModelUtil::ActorModelUtil()
{
    
}

ActorModelUtil::~ActorModelUtil()
{
    
}


ActorModelUtil* ActorModelUtil::getInstance()
{
    if (!_instance) {
        _instance = new ActorModelUtil();
    }
    return _instance;
}


Point ActorModelUtil::getActorAnchorPoint(int modelId)
{
    // TODO: todo:需要修改获取 行 的方法
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float pointX = csvUtil->getDouble(row, CsvRoleModelProperty::en_anchorPointX, "GDGameRes/CSV/RoleModel.csv");
    float pointY = csvUtil->getDouble(row, CsvRoleModelProperty::en_anchorPointY, "GDGameRes/CSV/RoleModel.csv");
    return Vec2(pointX, pointY);
}

Point ActorModelUtil::getActorAttackPoint(int modelId)
{
    // TODO: todo:需要修改获取 行 的方法
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float pointX = csvUtil->getDouble(row, CsvRoleModelProperty::en_attackPointX, "GDGameRes/CSV/RoleModel.csv");
    float pointY = csvUtil->getDouble(row, CsvRoleModelProperty::en_attackPointY, "GDGameRes/CSV/RoleModel.csv");
    return Vec2(pointX, pointY);
}

Point ActorModelUtil::getActorSkillPoint(int modelId)
{
    // TODO: todo:需要修改获取 行 的方法
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float pointX = csvUtil->getDouble(row, CsvRoleModelProperty::en_skillPointX, "GDGameRes/CSV/RoleModel.csv");
    float pointY = csvUtil->getDouble(row, CsvRoleModelProperty::en_skillPointY, "GDGameRes/CSV/RoleModel.csv");
    return Vec2(pointX, pointY);
}


Size ActorModelUtil::getActorWatchSize(int modelId)
{
    return Size(800,800);
}

Size ActorModelUtil::getActorAttackSize(int modelId)
{
    // TODO: todo:需要修改获取 行 的方法
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float width = csvUtil->getDouble(row, CsvRoleModelProperty::en_attackSize_width, "GDGameRes/CSV/RoleModel.csv");
    float height = csvUtil->getDouble(row, CsvRoleModelProperty::en_attackSize_height, "GDGameRes/CSV/RoleModel.csv");
    return Size(width, height);
}

Size ActorModelUtil::getActorHurtSize(int modelId)
{
    // TODO: todo:需要修改获取 行 的方法
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float width = csvUtil->getDouble(row, CsvRoleModelProperty::en_hurtSize_width, "GDGameRes/CSV/RoleModel.csv");
    float height = csvUtil->getDouble(row, CsvRoleModelProperty::en_hurtSize_height, "GDGameRes/CSV/RoleModel.csv");
    return Size(width, height);
}

