//
//  GameRocker.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/21.
//

#include "GameRocker.h"

USING_NS_CC;
#define PI 3.141592654



GameRocker::GameRocker(){}

GameRocker::~GameRocker(){}


GameRocker* GameRocker::createWithFilename(const std::string &barFilename, const std::string &bgFilename)
{
    GameRocker* rocker = new (std::nothrow) GameRocker();
    if (rocker && rocker->initWithFilename(barFilename, bgFilename)) {
        rocker->autorelease();
        return rocker;
    }else{
        CC_SAFE_DELETE(rocker);
        return nullptr;
    }
}


const Size& GameRocker::getContentSize() const
{
    if (rockerBG) {
        return rockerBG->getContentSize();
    }
    return Size::ZERO;
}

void GameRocker::setupDirectionStateCallback(const GameRocker::StateChangeCallback &callback)
{
    _changeCallback = callback;
}


bool GameRocker::initWithFilename(const std::string &barFilename, const std::string &bgFilename)
{
    if (Node::init())
    {
        auto barFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(barFilename);
        rockerBar = barFrame ? Sprite::createWithSpriteFrame(barFrame) : Sprite::create(barFilename);
        
        auto bgFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(bgFilename);
        rockerBG = bgFrame ? Sprite::createWithSpriteFrame(bgFrame) : Sprite::create(bgFilename);
        
        CCASSERT(rockerBG && rockerBar, "GameRocker : (rockerBG or rockerBar) can not nullprt");
        
//        rockerBG = Sprite::create(bgFilename);
//        rockerBar = Sprite::create(barFilename);
        rockerBar->setPosition(rockerBG->getContentSize().width/2,rockerBG->getContentSize().height/2);
        rockerBG->addChild(rockerBar);
        this->addChild(rockerBG);
        setContentSize(rockerBG->getContentSize());
        _normalRadius = rockerBG->getContentSize().width * 0.4;
        _quickRadius = rockerBG->getContentSize().width * 0.5;
        _enable = true;
        _movable = false;
        _moveRect = Rect(0, 0, 0, 0);
        _keysType = GameRocker::KeysType::Key_4;
        addTouchEvent();
        return true;
    }
    return false;
}


void GameRocker::onEnter()
{
    Node::onEnter();
    _initPosition = this->getPosition();
}


void GameRocker::addTouchEvent()
{
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(false);
    listener->onTouchBegan = [this](Touch* touch, Event* evnt)->bool
    {
        if (_movable)
        {
            if (_moveRect.containsPoint(touch->getLocation()))
            {
                this->setPosition(touch->getLocation());
                return true;
            }
            return false;
        }else{
            Rect rockerRect = Rect(this->getPositionX() - _normalRadius, this->getPositionY() - _normalRadius, _normalRadius*2, _normalRadius*2);
            Rect rect = this->getBoundingBox();
            rect.origin = rect.origin - Vec2(rockerBG->getContentSize().width/2,rockerBG->getContentSize().height/2);
            return rockerRect.containsPoint(touch->getLocation());
        }
    };
    
    listener->onTouchMoved = [this](Touch* touch, Event* evnt)
    {
        if (!_enable) return;

        // 获取角度
        Point p1 = this->getPosition();
        Point p2 = touch->getLocation();
        float rad = getRad(p1, p2);
        // 用户触摸点到摇杆的中心的距离
        float touchRadius = sqrt(pow(touch->getLocation().x - this->getPositionX(), 2) + pow(touch->getLocation().y - this->getPositionY(), 2));
        
        float radius = MIN(_normalRadius, touchRadius);
        
        GameRockerState tempState;
        if (touchRadius >= _quickRadius) {
            // 加速状态
            radius = _quickRadius;
            rockerBG->setColor(Color3B::RED);
            tempState.setSpeedState(GameRockerState::SpeedState::QuickState);
        }else{
            // 普通状态
            rockerBG->setColor(Color3B::WHITE);
            tempState.setSpeedState(GameRockerState::SpeedState::NormalState);
        }
        // 设置 摇杆的位置
        Point barPoint = Vec2(radius * cos(rad), radius * sin(rad)) + Vec2(rockerBG->getContentSize().width/2,rockerBG->getContentSize().height/2);
        rockerBar->setPosition(barPoint);
        // 弧度转化成脚步
        float angle = 180.f / PI * rad;
        if (_keysType == GameRocker::KeysType::Key_4) {
            if ((angle >= 0 && angle < 45) || (angle >= 315 && angle < 360)) {//右
                tempState.setDirection(GameRockerState::DirectionType::RightType);
            }
            if (angle >= 45 && angle < 135) { //上
                tempState.setDirection(GameRockerState::DirectionType::UpType);
            }
            if (angle >= 135 && angle < 225) { //左
                tempState.setDirection(GameRockerState::DirectionType::LeftType);
            }
            if (angle >= 225 && angle < 315) { //下
                tempState.setDirection(GameRockerState::DirectionType::DownType);
            }
        }
        if (_keysType == GameRocker::KeysType::Key_8) {
            if ((angle >= 0 && angle < 22.5) || (angle >= 337.5 && angle < 360)) {//右
                tempState.setDirection(GameRockerState::DirectionType::RightType);
            }
            if (angle >= 22.5 && angle < 67.5) { //右上
                tempState.setDirection(GameRockerState::DirectionType::RightUpType);
            }
            if (angle >= 67.5 && angle < 112.5) { //上
                tempState.setDirection(GameRockerState::DirectionType::UpType);
            }
            if (angle >= 112.5 && angle < 157.5) { //左上
                tempState.setDirection(GameRockerState::DirectionType::LeftUpType);
            }
            if (angle >= 157.5 && angle < 202.5) { //左
                tempState.setDirection(GameRockerState::DirectionType::LeftType);
            }
            if (angle >= 202.5 && angle < 247.5) { //左下
                tempState.setDirection(GameRockerState::DirectionType::LeftDownType);
            }
            if (angle >= 247.5 && angle < 292.5) { //下
                tempState.setDirection(GameRockerState::DirectionType::DownType);
            }
            if (angle >= 292.5 && angle < 337.5) { //右下
                tempState.setDirection(GameRockerState::DirectionType::RightDownType);
            }
        }
        
        // 改变摇杆Bar的状态
        changeRockerState(tempState);
    };
    auto touchEndCallback = [this](Touch* touch, Event* evnt)
    {
        CCLOG("Layer touch  move  (%f,%f)",touch->getLocation().x,touch->getLocation().y);
        rockerBar->setPosition(rockerBG->getContentSize().width/2,rockerBG->getContentSize().height/2);
        rockerBG->setColor(Color3B::WHITE);
        this->setPosition(_initPosition);
        GameRockerState tempState;
        changeRockerState(tempState);
    };
    listener->onTouchEnded = touchEndCallback;
    listener->onTouchCancelled = touchEndCallback;
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}


void GameRocker::changeRockerState(const GameRockerState &state)
{
    if (_rockerState == state) return;
    _rockerState = state;
    if (_changeCallback) _changeCallback(_rockerState);
}


/**
 * 获取以p1为圆心，p2p1与x轴的弧度值
 */
float GameRocker::getRad(cocos2d::Point p1, cocos2d::Point p2)
{
    float xx = p2.x - p1.x;
    float yy = p2.y - p1.y;
    // 斜边
    float xie = sqrt(pow(xx, 2) + pow(yy, 2));
    // yy >= 0 弧度在于 0 到 π 之间。(0~180°)
    // yy < 0 弧度在于 π 到 2π 之间。(180°~360°)
    float rad = yy >= 0 ? (acos(xx / xie)) : (PI * 2 - acos(xx / xie));
    return rad;
}










