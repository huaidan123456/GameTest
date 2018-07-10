//
//  Hero.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/4.
//

#ifndef Hero_h
#define Hero_h

#include <stdio.h>
#include "Entity.h"
#include "HeroState.h"



class Hero:public Entity
{
public:
    static Hero* createWithRId(const int& rid);
    Hero();
    virtual ~Hero() override;
    
    virtual bool init(const int &rId) override;

    
    
public:
    
    void handleInputCmd(HeroCmd* cmd);
    
    /**
     *  动作
     */
    void standingIdle();
    void standingIdle2();
    void moveLeft();
    void moveRight();
    
    void attack(int stage);
    void death();
    
    inline const EntitySpeed& getHeroSpeed() const {return _speed;};
    
protected:
    void listenerMove(float time);
    
    
    
    
private:
    // 英雄的级别
    int _evolutionLevel = 1;
    // 英雄状态
    HeroState* _state;
    // 速度
    EntitySpeed _speed;
    
    
};

#endif /* Hero_h */
