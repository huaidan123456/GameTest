//
//  BloodStripView.h
//  GameTest-mobile
//
//  Created by Allen on 2018/7/19.
//

#ifndef BloodStripView_h
#define BloodStripView_h

#include <stdio.h>
#include "cocos2d.h"


USING_NS_CC;


class BloodStripView:public Node
{
public:
    static BloodStripView* create(const std::string pressBar,const std::string pressBg);
    BloodStripView();
    ~BloodStripView();
    
    
    /**
     设置百分比 （0~1）
     */
    void setProgress(float progress);
    
    
protected:
    virtual bool init() override;
    virtual bool init(const std::string pressBar,const std::string pressBg);
    
protected:
    Sprite* _pBg;
    ProgressTimer* _pProgressBar;
    
    
    std::string _barImageName;
    std::string _bgImageName;
    
    
    float _progress;
    
};

#endif /* BloodStripView_h */
