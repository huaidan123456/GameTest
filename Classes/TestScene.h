//
//  TestScene.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/11.
//

#ifndef TestScene_h
#define TestScene_h

#include <stdio.h>
#include "TestScene.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class TestScene:public Scene
{
public:
    CREATE_FUNC(TestScene);
    
    virtual bool init() override;
    
    
    void addSpriteToSceneWithIndex(int index);
    
    /**
     *  通过 SpriteFrameCache 缓存来进行渲染的
     */
    void addSpriteToScene();
    /**
     *  通过 SpriteBatchNode 来实现渲染的
     */
    void addSpriteToScene2();
    
    void startAniamtion(Node* node);
    
    
private:
    Sprite* bg;
    SpriteBatchNode * batchNode;
};

#endif /* TestScene_h */
