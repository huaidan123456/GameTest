//
//  BloodStripView.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/7/19.
//

#include "BloodStripView.h"


BloodStripView::BloodStripView()
{
    
}

BloodStripView::~BloodStripView()
{
    
}

BloodStripView* BloodStripView::create(const std::string pressBar, const std::string pressBg)
{
    BloodStripView* view = new (std::nothrow) BloodStripView();
    if (view && view->init(pressBar,pressBg)) {
        return view;
    }else{
        CC_SAFE_DELETE(view);
        return nullptr;
    }
}


bool BloodStripView::init()
{
    return Node::init();
}


bool BloodStripView::init(const std::string pressBar, const std::string pressBg)
{
    if (init()) {
        _progress = 100;
        
        
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pressBg);
        _pBg = frame ? Sprite::createWithSpriteFrame(frame) : Sprite::create(pressBg);
        this->addChild(_pBg);
        
        auto barFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(pressBar);
        auto barSprite = barFrame ? Sprite::createWithSpriteFrame(barFrame) : Sprite::create(pressBar);
        
        _pProgressBar = ProgressTimer::create(barSprite);
        _pProgressBar->setType(ProgressTimer::Type::BAR);
        _pProgressBar->setMidpoint(Vec2(0, 0.5));
        _pProgressBar->setPercentage(_progress);
        this->addChild(_pProgressBar,1);
        
        return true;

    }
    return false;
}


//============================
// !!!: public
//============================
void BloodStripView::setProgress(float progress)
{
    _pProgressBar->stopAllActions();
    _pProgressBar->setPercentage(_progress);
    
    float percent = progress * 100;
    float duration = 1.f / (_progress - percent);
    _progress = percent;
    if (duration < 0.05) {
        _pProgressBar->setPercentage(_progress);
    }else{
        _pProgressBar->runAction(ProgressTo::create(duration, _progress));
    }
    
}

