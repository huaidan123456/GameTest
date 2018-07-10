//
//  CrashCheckScene.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/20.
//

#ifndef CrashCheckScene_h
#define CrashCheckScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class CrashCheckScene:public Scene
{
public:
    CREATE_FUNC(CrashCheckScene);
    
    virtual bool init() override;
    
    virtual void update(float delta) override;
    void loadSubview();
    
    
    
private:
    Sprite* sp1;
    Sprite* sp2;
    
    Sprite* sp3;
    Sprite* sp4;
    
    Sprite* sp00;
    
};

#endif /* CrashCheckScene_h */
