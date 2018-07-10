//
//  Entity.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/4.
//

/**
 *  实体类
 */
#ifndef Entity_h
#define Entity_h

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class EntitySpeed
{
public:
    // TODO: todo:可以将方向修改成角度
    int direction = 0;  //方向 1 为向右  0 为向左
    float speed = 0;
};

class Entity:public Node
{
public:
    
    virtual ~Entity();
    virtual bool init(const int &rId);
    
    virtual const Size& getContentSize()const;
    
    
    virtual void bindSprite(Sprite* pSprite);
    virtual Sprite* getSprite();
    
    
private:
    Sprite* _pSprite;
    
};


#endif /* Entity_h */
