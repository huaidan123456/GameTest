//
//  RoleModelUtil.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/6.
//

#ifndef RoleModelUtil_h
#define RoleModelUtil_h

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class RoleModelUtil
{
public:
    static RoleModelUtil* getInstance();
    
    
    Point getRoleAnchorPoint(int modelId);
    
    Size getRoleHurtSize(int modelId);
    
    Size getRoleAttackSize(int modelId);
    
    Point getRoleAttackPoint(int modelId);
    
    Point getRoleSkillPoint(int modelId);
    
    
    
    
    
protected:
    ~RoleModelUtil();
private:
    RoleModelUtil();
    
    RoleModelUtil(const RoleModelUtil &rUtil) = delete;
    
    RoleModelUtil &operator=(const RoleModelUtil &rUtil) = delete;
    
    
    
private:
    static RoleModelUtil* _instance;
};

#endif /* RoleModelUtil_h */
