//
//  GameRoleA.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/3.
//

#include "GameRoleA.h"
#include "GameRoleCmd.h"
#include "GameRoleState.h"
#include "GameRoleStandState.h"
#include "GameRoleWalkState.h"
#include "GameRoleRunState.h"
#include "RoleModelUtil.h"
#include "BloodStripView.h"

#include "FightTestManager.h"


#define DO_MOVE_TIME 0.2

GameRoleA::GameRoleA(int roleId)
{
    _roleId = roleId;
}

GameRoleA::~GameRoleA()
{
    unscheduleAllCallbacks();
    CC_SAFE_DELETE(_actionState);
}

bool GameRoleA::init()
{
    if (EntityTestBase::init()) {
        
        initRole();
        return true;
    }
    return false;
}

void GameRoleA::initRole()
{
    _pShadow = Sprite::create("GDGameRes/fightImg/role_shadow.png");
    _pShadow->setPosition(0,0);
    this->addChild(_pShadow);
    
    _pRole = Sprite::createWithSpriteFrameName(StringUtils::format("%d_stand_0000.png",_roleId));
    _pRole->setAnchorPoint(RoleModelUtil::getInstance()->getRoleAnchorPoint(_roleId));
    _pRole->setPosition(0, 0);
    this->addChild(_pRole,2);
    
    _pAtkEffectNode = Node::create();
    this->addChild(_pAtkEffectNode,3);
    
    _pSkillEffectNode = Node::create();
    this->addChild(_pSkillEffectNode,3);
    
    _pBloodView = BloodStripView::create("GDGameRes/ui/fightUI/xuetiao_bar.png", "GDGameRes/ui/fightUI/xuetiao_bg.png");
    _pBloodView->setPosition(Vec2(0, -10));
    this->addChild(_pBloodView,2);
    
    _actionState = new GameRoleStandState();
    _actionState->enter(this);
    
    _speedWalk = 30;
    _speedRun = 60;
    _hpTotal = 1000;
    _hp = 1000;
    _atkBase = 100;
    _attackSize = RoleModelUtil::getInstance()->getRoleAttackSize(_roleId);
    _skillSize = RoleModelUtil::getInstance()->getRoleAttackSize(_roleId);
    _hurtSize = RoleModelUtil::getInstance()->getRoleHurtSize(_roleId);
    
    _directionEnable = true;
    _direction = DirectionTypeDefine::NoneType;
    _nowSpeed = 0;
    
    // 添加状态更新
    schedule([this](float ft){
        // 状态更新
        _actionState->update(this);
    }, 0.1f, "GameRoleStateUpdate");
}


/**
 接收命令的方法
 @param cmd 命令
 */
void GameRoleA::handleInputCmd(GameRoleCmd* cmd)
{
    if (cmd) {
        if (!_directionEnable && (cmd->getCommand() == GameRoleCmd::Command::WalkingCmd || cmd->getCommand() == GameRoleCmd::Command::RunningCmd || cmd->getCommand() == GameRoleCmd::Command::StandingCmd)) {
            return;
        }
        GameRoleState* actionState = _actionState->handleCommand(this, cmd);
        if (actionState != nullptr) {
            if (actionState != _actionState) {
                CC_SAFE_DELETE(_actionState);
                _actionState = actionState;
            }
            _actionState->enter(this);
        }
    }
}


void GameRoleA::resetInitActionState()
{
    CC_SAFE_DELETE(_actionState);
    _actionState = new GameRoleStandState();
    _actionState->enter(this);
}


/**
 *  获取攻击范围
 */
Rect GameRoleA::getRoleAttackRect()
{
    
    if (isRoleDirectionRight()) {
        return Rect(getPositionX(), getPositionY()-_attackSize.height/2, _attackSize.width, _attackSize.height);
    }else{
        return Rect(getPositionX()-_attackSize.width, getPositionY()-_attackSize.height/2, _attackSize.width, _attackSize.height);
    }
}

/**
 *  获取技能范围
 */
Rect GameRoleA::getRoleSkillAtkRect()
{
    return Rect(getPositionX(), getPositionY()-_skillSize.height/2, _skillSize.width, _skillSize.height);
}


/**
 *  获取被攻击范围
 */
Rect GameRoleA::getRoleHurtRect()
{
    return Rect(getPositionX()-_hurtSize.width/2, getPositionY()-_hurtSize.height/2, _hurtSize.width, _hurtSize.height);
}

/**
 *  获取角色的视野范围
 */
Rect GameRoleA::getRoleWatchRect()
{
    return Rect(getPositionX()-_watchSize.width/2, getPositionY()-_watchSize.height/2, _watchSize.width, _watchSize.height);
}



void GameRoleA::doAttackEnemyAs(int atk)
{
    FightTestManager::getInstance()->attackEnemyAs(getRoleAttackRect(), atk);
}

void GameRoleA::doLoseHp(int loseNum)
{
    _hp = MAX(0, _hp - loseNum);
    _pBloodView->setProgress((float)_hp/(float)_hpTotal);
    if (_hp == 0) {
        handleInputCmd(GameRoleCmd::create(GameRoleCmd::Command::DeathCmd));
        CCLOG("死了");
    }
}



/**
 *  动作
 */
void GameRoleA::standingWaitAction()
{
    _directionEnable = true;
    stopAllActionAnimation();
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_stand",_roleId));
    if (anim) {
        anim->setLoops(-1);
        _pRole->runAction(Animate::create(anim));
    }
    
//    resetAttackStage();
}

void GameRoleA::standingIdleAction()
{
    _directionEnable = true;
    
    stopAllActionAnimation();
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_stand",_roleId));
    if (anim) {
        anim->setLoops(-1);
        _pRole->runAction(Animate::create(anim));
    }
//    resetAttackStage();
}

void GameRoleA::walkingAction(DirectionTypeDefine directionType)
{
    _directionEnable = true;
    stopAllActionAnimation();
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_walk",_roleId));
    if (anim) {
        anim->setLoops(-1);
        _pRole->runAction(Animate::create(anim));
    }
    _nowSpeed = _speedWalk;
    _direction = directionType;
    this->listenerMove(DO_MOVE_TIME);

    switch (_direction) {
        case DirectionTypeDefine::LeftType:
        case DirectionTypeDefine::LeftUpType:
        case DirectionTypeDefine::LeftDownType:
            setupRoleFlippedX(true);
            break;
        case DirectionTypeDefine::RightType:
        case DirectionTypeDefine::RightUpType:
        case DirectionTypeDefine::RightDownType:
            setupRoleFlippedX(false);
            
            break;
        default:
            break;
    }
    
//    resetAttackStage();
}

void GameRoleA::runningAction(DirectionTypeDefine directionType)
{
    _directionEnable = true;
    stopAllActionAnimation();
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_run",_roleId));
    if (anim) {
        anim->setLoops(-1);
        _pRole->runAction(Animate::create(anim));
    }
    
    _nowSpeed = _speedRun;
    _direction = directionType;
    this->listenerMove(DO_MOVE_TIME);
    
    switch (_direction) {
        case DirectionTypeDefine::LeftType:
        case DirectionTypeDefine::LeftUpType:
        case DirectionTypeDefine::LeftDownType:
            setupRoleFlippedX(true);
            break;
        case DirectionTypeDefine::RightType:
        case DirectionTypeDefine::RightUpType:
        case DirectionTypeDefine::RightDownType:
            setupRoleFlippedX(false);
            break;
        default:
            break;
    }
//    resetAttackStage();
}

void GameRoleA::attackAction()
{
    if (!_changeAttackEnable) return;
     _directionEnable = false;
    
    stopAllActionAnimation();
    
    // 攻击效果
    if (_attackStage == 0 || _attackStage == 1) {
        auto effectAnim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_attack_effect",_roleId));
        auto effect = Sprite::createWithSpriteFrameName(StringUtils::format("%d_attack_effect_0000.png",_roleId));
        auto atkPoint = RoleModelUtil::getInstance()->getRoleAttackPoint(_roleId);
        effect->setAnchorPoint(isRoleDirectionRight() ? atkPoint : (Vec2(1 - atkPoint.x,atkPoint.y)));
        effect->setName("effect");
        addAttackEffect(effect);
        auto effectAnction = Sequence::create(Animate::create(effectAnim),CallFunc::create([this]{
            this->removeAttackEffect("effect");
        }), NULL);
        effect->runAction(effectAnction);
    }
    
    Animation* anim = nullptr;
    if (_attackStage == 0) {
        anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_attack",_roleId));
    }else{
        anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_attack_%d",_roleId,_attackStage));
    }
    
    if (anim) {
        anim->setLoops(1);
        float animTime = ((float)anim->getFrames().size()) * anim->getDelayPerUnit();
        float delay =  animTime + 1;

        unschedule("GameRole_Attack");
        scheduleOnce([this](float ft){
            this->resetAttackStage();
        }, delay, "GameRole_Attack");
        
        
        auto action = Sequence::create(Animate::create(anim),CallFunc::create([this]{
            _changeAttackEnable = true;
            _actionState->exit(this);
        }), NULL);
        
        
        auto atkEnemyAct = Sequence::create(DelayTime::create(animTime/2.f),CallFunc::create([this]{
            this->doAttackEnemyAs(_atkBase * (1 + _attackStage * 0.1));
        }), NULL);
        
        _changeAttackEnable = false;
        _attackStage++;
        _pRole->runAction(Spawn::create(action,atkEnemyAct, NULL));
    }

    _attackStage = _attackStage >= 6 ? 0 : _attackStage;
}

void GameRoleA::hurtAction()
{
    _directionEnable = false;
    stopAllActionAnimation();
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_hurt",_roleId));
    anim->setRestoreOriginalFrame(false);
    anim->setDelayPerUnit(0.3f / anim->getFrames().size());
    if (anim) {
        anim->setLoops(1);
        _pRole->runAction(Animate::create(anim));
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
            
            _actionState->exit(this);
        }), NULL));
    }

    resetAttackStage();
}



void GameRoleA::skill1Action()
{
    _directionEnable = false;
    stopAllActionAnimation();
    
    auto anim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_skill",_roleId));
    if (anim) {
        anim->setLoops(1);
        _pRole->runAction(Sequence::create(Animate::create(anim),CallFunc::create([this]{
            _actionState->exit(this);
        }), NULL));
    }
    
    float animTime = anim->getFrames().size()*anim->getDelayPerUnit();
    auto atkAct = CallFunc::create([this]{
        this->doAttackEnemyAs(_atkBase * 1.5);
    });
    auto atkEnemyAct = Sequence::create(DelayTime::create(animTime*0.3),atkAct,DelayTime::create(animTime*0.3),atkAct, NULL);
    this->runAction(atkEnemyAct);
    
    // 创建技能效果
    auto effectAnim = AnimationCache::getInstance()->getAnimation(StringUtils::format("%d_skill_effect",_roleId));
    auto effect = Sprite::createWithSpriteFrameName(StringUtils::format("%d_skill_effect_0000.png",_roleId));
    effect->setAnchorPoint(RoleModelUtil::getInstance()->getRoleSkillPoint(_roleId));
    effect->setName("skillEffect");
    addSkillEffect(effect);
    
    auto effectAnction = Sequence::create(Animate::create(effectAnim),CallFunc::create([this]{
        this->removeSkillEffect("skillEffect");
    }), NULL);
    effect->runAction(effectAnction);
    
    resetAttackStage();
}

void GameRoleA::skill2Action()
{
    resetAttackStage();
}

void GameRoleA::skill3Action()
{
    resetAttackStage();
}

void GameRoleA::skill4Action()
{
    resetAttackStage();
}

void GameRoleA::skill5Action()
{
    resetAttackStage();
}

void GameRoleA::deathAction()
{
    _directionEnable = false;
    
    stopAllActionAnimation();
    
    _pRole->setDisplayFrameWithAnimationName(StringUtils::format("%d_hurt",_roleId), 1);
    _pRole->setColor(Color3B::BLACK);
    resetAttackStage();
}




void GameRoleA::listenerMove(float time)
{
    // 当速度小于 0.01时候 认为是静止的
    if (_nowSpeed >= 0.01) {
        auto pMoveCall = CallFunc::create([this,time]{
            this->listenerMove(time);
        });
        
        Point movePoint;
        float rate = 1/sqrt(2);
        switch (_direction) {
            case DirectionTypeDefine::LeftType:
                movePoint = Vec2(-_nowSpeed, 0);
                break;
            case DirectionTypeDefine::LeftUpType:
                movePoint = Vec2(-_nowSpeed* rate, _nowSpeed* rate);
                break;
            case DirectionTypeDefine::UpType:
                movePoint = Vec2(0, _nowSpeed);
                break;
            case DirectionTypeDefine::RightUpType:
                movePoint = Vec2(_nowSpeed* rate, _nowSpeed* rate);
                break;
            case DirectionTypeDefine::RightType:
                movePoint = Vec2(_nowSpeed, 0);
                break;
            case DirectionTypeDefine::RightDownType:
                movePoint = Vec2(_nowSpeed, -_nowSpeed* rate);
                break;
            case DirectionTypeDefine::DownType:
                movePoint = Vec2(0, -_nowSpeed);
                break;
            case DirectionTypeDefine::LeftDownType:
                movePoint = Vec2(-_nowSpeed* rate, -_nowSpeed* rate);
                break;
            default:
                break;
        }
        this->runAction(Sequence::create(MoveBy::create(time, movePoint),pMoveCall, NULL));
    }
}


void GameRoleA::resetAttackStage()
{
    _attackStage = 0;
    _changeAttackEnable = true;
}



void GameRoleA::stopAllActionAnimation()
{
    _pRole->stopAllActions();
    this->stopAllActions();
    _pRole->setDisplayFrameWithAnimationName(StringUtils::format("%d_stand",_roleId), 0);
    
    // 移除攻击效果
    _pAtkEffectNode->removeAllChildren();
    // 移除受伤效果
    if (_pHurt) {
        _pHurt->removeFromParent();
        _pHurt = nullptr;
    }
}

void GameRoleA::setupRoleFlippedX(bool isFlipped)
{
    _pRole->setFlippedX(isFlipped);
    // TODO: todo:以后要添加效果的反转
    
    // 更改攻击范围
}

bool GameRoleA::isRoleFlippedX()
{
    return _pRole->isFlippedX();
}

void GameRoleA::addAttackEffect(Sprite* sp, int zOrder)
{
    if (!_pAtkEffectNode) {
        _pAtkEffectNode = Node::create();
        this->addChild(_pAtkEffectNode,3);
    }
    sp->setFlippedX(isRoleFlippedX());
    _pAtkEffectNode->addChild(sp,zOrder);
}

void GameRoleA::removeAttackEffect(const std::string &name)
{
    auto effect = _pAtkEffectNode->getChildByName(name);
    if (effect) {
        effect->removeFromParent();
    }
}

// 添加技能效果Sprite*
void GameRoleA::addSkillEffect(Sprite* sp, int zOrder)
{
    if (!_pSkillEffectNode) {
        _pSkillEffectNode = Node::create();
        this->addChild(_pSkillEffectNode,3);
    }
    sp->setFlippedX(isRoleFlippedX());
    _pSkillEffectNode->addChild(sp,zOrder);
    
}

void GameRoleA::removeSkillEffect(const std::string& name)
{
    auto effect = _pSkillEffectNode->getChildByName(name);
    if (effect) {
        effect->removeFromParent();
    }
}

