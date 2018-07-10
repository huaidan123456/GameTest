//
//  Hero.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/4.
//

#include "Hero.h"
#include "HeroStandingState.h"
#include "HeroCmd.h"

#define MOVETIME 0.5

Hero* Hero::createWithRId(const int &rid)
{
    Hero* ret = new (std::nothrow) Hero();
    if (ret && ret->init(rid)) {
        ret->autorelease();
        return ret;
    }else{
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

Hero::Hero()
{
    
}

Hero::~Hero()
{
    unscheduleAllCallbacks();
    CC_SAFE_DELETE(_state);
}

bool Hero::init(const int &rId)
{
    if (Entity::init(rId)) {
        // TODO: todo: init();
        _speed = EntitySpeed();
        _speed.direction = 0;
        _speed.speed = 40;
        
        // 设置状态
        _state = new HeroStandingState();
        _state->enter(this);
        
        // 添加更新
        schedule([this](float ft){
            
            // 状态更新
            _state->update(this);
        }, 0.1f, "HeroUpdate");

        return true;
    }
    
    return false;
}



void Hero::handleInputCmd(HeroCmd *cmd)
{
    if (cmd) {
        HeroState* state = _state->handleCommand(this, cmd);
        if (state != nullptr) {
            if (_state != state) {
                delete _state;
                _state = state;
            }
            _state->enter(this);
        }
    }
}


//============================
// !!!:动作
//============================
void Hero::standingIdle()
{
    getSprite()->stopAllActions();
    this->stopAllActions();
    getSprite()->setDisplayFrameWithAnimationName(StringUtils::format("Character_B_04_idle01_0%d",_evolutionLevel), 0);
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("Character_B_04_idle01_0%d",_evolutionLevel));
    anim->setDelayPerUnit(0.2f);
    getSprite()->runAction(Animate::create(anim));
}

void Hero::standingIdle2()
{
    getSprite()->stopAllActions();
    this->stopAllActions();
    getSprite()->setDisplayFrameWithAnimationName(StringUtils::format("Character_B_04_idle01_0%d",_evolutionLevel), 0);
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("Character_B_04_idle02_0%d",_evolutionLevel));
    anim->setDelayPerUnit(0.2f);
    getSprite()->runAction(Animate::create(anim));
}

void Hero::moveLeft()
{
    getSprite()->stopAllActions();
    this->stopAllActions();
    getSprite()->setDisplayFrameWithAnimationName(StringUtils::format("Character_B_04_idle01_0%d",_evolutionLevel), 0);
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("Character_B_04_move_0%d",_evolutionLevel));
    getSprite()->runAction(Animate::create(anim));
    _speed.direction = 0;
    getSprite()->setFlippedX(false);
    
    this->listenerMove(MOVETIME);
}

void Hero::moveRight()
{
    getSprite()->stopAllActions();
    this->stopAllActions();
    getSprite()->setDisplayFrameWithAnimationName(StringUtils::format("Character_B_04_idle01_0%d",_evolutionLevel), 0);
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("Character_B_04_move_0%d",_evolutionLevel));
    getSprite()->runAction(Animate::create(anim));
    _speed.direction = 1;
    getSprite()->setFlippedX(true);
    
    this->listenerMove(MOVETIME);
}

void Hero::attack(int stage)
{
    getSprite()->stopAllActions();
    this->stopAllActions();
    getSprite()->setDisplayFrameWithAnimationName(StringUtils::format("Character_B_04_idle01_0%d",_evolutionLevel), 0);
    
    Animation* anim = nullptr;
    if (stage == 1) {
        anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("Character_B_04_attack_0%d",_evolutionLevel));
        anim->setLoops(1);
        anim->setDelayPerUnit(0.1f);
    }else{
        anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("Character_B_04_attackS_0%d",_evolutionLevel));
        anim->setLoops(1);
        anim->setDelayPerUnit(0.1f);
    }
    
    getSprite()->runAction(Sequence::create(Animate::create(anim),NULL));
}

void Hero::death()
{
    getSprite()->stopAllActions();
    this->stopAllActions();
    getSprite()->setDisplayFrameWithAnimationName(StringUtils::format("Character_B_04_idle01_0%d",_evolutionLevel), 0);
    
    auto anim = AnimationCache::getInstance()->getAnimation("Character_B_04_death_01");
    getSprite()->runAction(Animate::create(anim));
}

void Hero::listenerMove(float time)
{
    if (_speed.speed != 0)
    {
        auto pMoveCall = CallFunc::create([this]{
            this->listenerMove(MOVETIME);
        });
        
        float speed = _speed.direction == 1 ? _speed.speed : -_speed.speed;
        this->runAction(Sequence::create(MoveBy::create(MOVETIME, Vec2(speed, 0)), pMoveCall,NULL));
    }
}
