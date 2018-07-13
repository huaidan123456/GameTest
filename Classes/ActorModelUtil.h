//
//  ActorModelUtil.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/13.
//

#ifndef ActorModelUtil_h
#define ActorModelUtil_h

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class ActorModelUtil
{
public:
    static ActorModelUtil* getInstance();
    
    
    Point getActorAnchorPoint(int modelId);
    
    Point getActorAttackPoint(int modelId);
    
    Point getActorSkillPoint(int modelId);
    
    Size getActorWatchSize(int modelId);
    
    Size getActorAttackSize(int modelId);
    
    Size getActorHurtSize(int modelId);
    
    
    
    
    
protected:
    ~ActorModelUtil();
private:
    ActorModelUtil();
    
    ActorModelUtil(const ActorModelUtil &rUtil) = delete;
    
    ActorModelUtil &operator=(const ActorModelUtil &rUtil) = delete;
    
    
    
private:
    static ActorModelUtil* _instance;
};

#endif /* ActorModelUtil_h */
