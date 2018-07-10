//
//  GameRocker.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/21.
//

#ifndef GameRocker_h
#define GameRocker_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

/**
 *  摇杆状态类
 */
class GameRockerState
{
public:
    
    /**
     *  摇杆方向枚举
     */
    enum class DirectionType
    {
        StayType,
        LeftType,
        LeftUpType,
        UpType,
        RightUpType,
        RightType,
        RightDownType,
        DownType,
        LeftDownType,
    };
    
    /**
     *  速度状态
     */
    enum class SpeedState
    {
        StayState,
        NormalState,
        QuickState,
    };
    
public:
    GameRockerState():_direction(GameRockerState::DirectionType::StayType),_speedState(GameRockerState::SpeedState::StayState) {};
    GameRockerState(const GameRockerState& state){
        _direction = state.getDirection();
        _speedState = state.getSpeedState();
    };
    ~GameRockerState(){};
    
    GameRockerState operator = (const GameRockerState& state)
    {
        if(this == &state) return *this;
        _direction = state.getDirection();
        _speedState = state.getSpeedState();
        return *this;
    };
    
    bool operator == (const GameRockerState& state)
    {
        return (_direction == state.getDirection() && _speedState == state.getSpeedState());
    }
    
    bool operator != (const GameRockerState& state)
    {
        return !(*this==state);
    }

protected:
    CC_SYNTHESIZE_PASS_BY_REF(GameRockerState::DirectionType,_direction,Direction);
    CC_SYNTHESIZE_PASS_BY_REF(GameRockerState::SpeedState,_speedState,SpeedState);
};





/**
 *  摇杆类
 */
class GameRocker:public cocos2d::Node
{
public:
    typedef std::function<void(const GameRockerState&)> StateChangeCallback;
    
    /**
     *  速度状态
     */
    enum class KeysType
    {
        Key_4,// 四键位
        Key_8,// 八键位
    };
    
    
public:
    GameRocker();
    ~GameRocker();
    static GameRocker* createWithFilename(const std::string& barFilename,const std::string& bgFilename);
    virtual const cocos2d::Size& getContentSize()const;
    
    /**
     *  设置状态改变的监听回调
     */
    void setupDirectionStateCallback(const StateChangeCallback& callback);
    
    /**
     *  获取当前摇杆状态
     */
    inline const GameRockerState& getRockerState() const { return _rockerState; };
    
    
protected:
    bool initWithFilename(const std::string& barFilename,const std::string& bgFilename);
    
    virtual void onEnter() override;
    
    void addTouchEvent();
    
    void changeRockerState(const GameRockerState& state);
    
    float getRad(cocos2d::Point p1,cocos2d::Point p2);

private:
    cocos2d::Sprite* rockerBar;
    cocos2d::Sprite* rockerBG;
    
    /** 摇杆的正常活动半径 （指用于正常跑）*/
    float _normalRadius;
    /** 摇杆的加速活动半径（指用于快跑） */
    float _quickRadius;
    
    
    /** 摇杆状态 */
    GameRockerState _rockerState;
    /** 摇杆状态改变的回调函数 */
    StateChangeCallback _changeCallback;
    //** 最初的坐标 *//
    cocos2d::Vec2 _initPosition;
    
    /** 摇杆是否能够使用 */
    CC_SYNTHESIZE(bool,_enable,Enable);
    /** 摇杆是否是可移动 */
    CC_SYNTHESIZE(bool, _movable, Movable);
    /** 可移动的范围，GL坐标系 */
    CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Rect,_moveRect,MoveRect);
    /** 键位方向 */
    CC_SYNTHESIZE(GameRocker::KeysType,_keysType,KeysType);
    
};

#endif /* GameRocker_h */
