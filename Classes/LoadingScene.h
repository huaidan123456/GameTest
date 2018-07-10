//
//  LoadingScene.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/4.
//

#ifndef LoadingScene_h
#define LoadingScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class LoadingScene:public Scene
{
public:
    CREATE_FUNC(LoadingScene);
    LoadingScene();
    
    ~LoadingScene();
    
    virtual bool init() override;
    virtual void onEnter() override;
    virtual void onExit() override;
    
    void loadSubview();
    
    
    /**
     加载图片资源
     */
    void loadResources();
    /**
     *  加载动画
     */
    void loadAnimation();
    
    
private:
    int _totalNum;
    int _haveLoadedNum;
    
    
    Node* loadingLayer;
    Sprite* loadingBox;
    ui::LoadingBar* loadingBar;
    ui::Button* enterBtn;
};

#endif /* LoadingScene_h */
