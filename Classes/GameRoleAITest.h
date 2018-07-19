//
//  GameRoleAITest.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/17.
//

#ifndef GameRoleAITest_h
#define GameRoleAITest_h

#include <stdio.h>
#include "cocos2d.h"
#include "PublicDefine.h"

USING_NS_CC;


class GameEnemyA;
class GameRoleAITest:public Ref
{
public:
    CREATE_INSTANCE_FUNC(GameRoleAITest);
    DESTROY_INSTANCE_FUNC();
    
    bool init();
    
    void start();
    
    
    void addUpdate();
    
    void enemyRandomMove(GameEnemyA* enemy);
    
    
    
    
protected:
    GameRoleAITest(){
        _scheduler = Director::getInstance()->getScheduler();
        _scheduler->retain();
    };
    ~GameRoleAITest(){
        CC_SAFE_RELEASE_NULL(_scheduler);
    };
    
    
    void schedule(const std::function<void(float)> &callback, float interval, const std::string &key)
    {
        _scheduler->schedule(callback, this, interval, false, key);
    }
    
    void unschedule(const std::string &key)
    {
        _scheduler->unschedule(key, this);
    }
    
    void unscheduleAllCallbacks()
    {
        _scheduler->unscheduleAllForTarget(this);
    }
    
    
    Scheduler* _scheduler;
    
    
    Vector<GameEnemyA*> _randomEnemy;
    
};


#endif /* GameRoleAITest_h */
