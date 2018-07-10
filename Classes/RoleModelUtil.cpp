//
//  RoleModelUtil.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/6.
//

#include "RoleModelUtil.h"
#include "CsvConfigDefine.h"
#include "ALCsvUtil.h"



RoleModelUtil* RoleModelUtil::_instance;

RoleModelUtil::RoleModelUtil()
{
    
}

RoleModelUtil::~RoleModelUtil()
{
    
}


RoleModelUtil* RoleModelUtil::getInstance()
{
    if (!_instance) {
        _instance = new RoleModelUtil();
    }
    return _instance;
}


Point RoleModelUtil::getRoleAnchorPoint(int modelId)
{
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float pointX = csvUtil->getDouble(row, CsvRoleModelProperty::en_anchorPointX, "GDGameRes/CSV/RoleModel.csv");
    float pointY = csvUtil->getDouble(row, CsvRoleModelProperty::en_anchorPointY, "GDGameRes/CSV/RoleModel.csv");
    return Vec2(pointX, pointY);
}

Size RoleModelUtil::getRoleHurtSize(int modelId)
{
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float width = csvUtil->getDouble(row, CsvRoleModelProperty::en_hurtSize_width, "GDGameRes/CSV/RoleModel.csv");
    float height = csvUtil->getDouble(row, CsvRoleModelProperty::en_hurtSize_height, "GDGameRes/CSV/RoleModel.csv");
    return Size(width, height);
}

Size RoleModelUtil::getRoleAttackSize(int modelId)
{
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float width = csvUtil->getDouble(row, CsvRoleModelProperty::en_attackSize_width, "GDGameRes/CSV/RoleModel.csv");
    float height = csvUtil->getDouble(row, CsvRoleModelProperty::en_attackSize_height, "GDGameRes/CSV/RoleModel.csv");
    return Size(width, height);
}

Point RoleModelUtil::getRoleAttackPoint(int modelId)
{
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float pointX = csvUtil->getDouble(row, CsvRoleModelProperty::en_attackPointX, "GDGameRes/CSV/RoleModel.csv");
    float pointY = csvUtil->getDouble(row, CsvRoleModelProperty::en_attackPointY, "GDGameRes/CSV/RoleModel.csv");
    return Vec2(pointX, pointY);
}

Point RoleModelUtil::getRoleSkillPoint(int modelId)
{
    int row = modelId - 20000;
    auto csvUtil = ALCsvUtil::getInstance();
    float pointX = csvUtil->getDouble(row, CsvRoleModelProperty::en_skillPointX, "GDGameRes/CSV/RoleModel.csv");
    float pointY = csvUtil->getDouble(row, CsvRoleModelProperty::en_skillPointY, "GDGameRes/CSV/RoleModel.csv");
    return Vec2(pointX, pointY);
}
