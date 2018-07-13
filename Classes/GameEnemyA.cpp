//
//  GameEnemyA.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/11.
//

#include "GameEnemyA.h"
#include "RoleModelUtil.h"


GameEnemyA::GameEnemyA(int roleId)
{
    _roleId = roleId;
}

GameEnemyA::~GameEnemyA()
{
    
}

bool GameEnemyA::init()
{
    if (EntityTestBase::init()) {
        initRole();
        return true;
    }
    return false;
}

void GameEnemyA::initRole()
{
    _pShadow = Sprite::create("GDGameRes/fightImg/role_shadow.png");
    _pShadow->setPosition(0,0);
    this->addChild(_pShadow);
    
    _pRole = Sprite::createWithSpriteFrameName(StringUtils::format("%d_stand_0000.png",_roleId));
    _pRole->setAnchorPoint(Vec2(0.5, 0.33));
    this->addChild(_pRole,2);
    
    standingWaitAction();
    setupRoleFlippedX(true);
}

void GameEnemyA::standingWaitAction()
{
    stopAllActionAnimation();
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_stand",_roleId));
    if (anim) {
        anim->setLoops(-1);
        _pRole->runAction(Animate::create(anim));
    }
}

void GameEnemyA::hurtAction()
{
    stopAllActionAnimation();
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_hurt",_roleId));
    anim->setRestoreOriginalFrame(false);
    anim->setDelayPerUnit(0.3f / anim->getFrames().size());
    if (anim) {
        anim->setLoops(1);
        _pRole->runAction(Sequence::create(Animate::create(anim), NULL));
    }
    
    
    _pHurt = Sprite::createWithSpriteFrameName("blood_0000.png");
    _pHurt->setPosition(Vec2(0, 80));
    this->addChild(_pHurt,2);
    auto anim2 = AnimationCache::getInstance()->getAnimation("blood_Animation");
    anim2->setDelayPerUnit(0.03f);
    
    if (anim2) {
        anim2->setLoops(1);
        _pHurt->runAction(Sequence::create(Animate::create(anim2),CallFunc::create([this]{
            _pHurt->removeFromParent();
            _pHurt = nullptr;
            this->standingWaitAction();
        }), NULL));
    }
}



void GameEnemyA::stopAllActionAnimation()
{
    _pRole->stopAllActions();
    this->stopAllActions();
    _pRole->setDisplayFrameWithAnimationName(StringUtils::format("%d_stand",_roleId), 0);
    
    // 移除攻击效果
//    _pAtkEffectNode->removeAllChildren();
    // 移除受伤效果
    if (_pHurt) {
        _pHurt->removeFromParent();
        _pHurt = nullptr;
    }
}

/**
 *  获取攻击范围
 */
Rect GameEnemyA::getRoleAttackRect()
{
//    if (isRoleFlippedX()) {
//        return Rect(this->getPositionX(), this->getPositionY(), _attackSize.width, _attackSize.height);
//    }
//    else{
//        return Rect(this->getPositionX()-_attackSize.width, this->getPositionY()-_attackSize.height, _attackSize.width, _attackSize.height);
//    }
}


/**
 *  获取被攻击范围
 */
Rect GameEnemyA::getRoleHurtRect()
{
    auto hurtSize = Size(220, 50);
    auto rect = Rect(getPositionX()-hurtSize.width/2, getPositionY()-hurtSize.height/2, hurtSize.width, hurtSize.height);
    return rect;
}


void GameEnemyA::setupRoleFlippedX(bool isFlipped)
{
    _pRole->setFlippedX(isFlipped);
    // TODO: todo:以后要添加效果的反转
    
}

bool GameEnemyA::isRoleFlippedX()
{
    return _pRole->isFlippedX();
}


