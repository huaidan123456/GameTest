//
//  ALSceneExtension.h
//  GameTest-mobile
//
//  Created by Allen on 2018/6/29.
//

/**
 *  Scene的扩展类
 */

#ifndef ALSceneExtension_h
#define ALSceneExtension_h

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;


class ALSceneExtension:public Scene
{
public:
    virtual ~ALSceneExtension();

    virtual bool init() override;
    virtual void onEnter() override;
    virtual void onExit() override;
    

    virtual void onLoadLoading();
    virtual void onLoadResources();
    virtual void onLoadResourcesProgress(float percent);
    virtual void onLoadResourcesCompleted();
    virtual void onLoadScene();
    virtual void onEnterScene();
    virtual void onExitScene();
    
    
    virtual void addImageAsync(const std::string &filepath);
    
    virtual void removeAllResourcesCache();
    
    
    
public:
    typedef std::function<void(Texture2D*)> alAddImageCallback;
    
protected:
    alAddImageCallback _addImageCallback = nullptr;
    const alAddImageCallback& getAddImageCallback();
    
    virtual void loadImageAsync();
    
    
    
private:
    std::vector<std::string> _imagepathVector;
    int _loadedImageCount = 0;
};

#endif /* ALSceneExtension_h */
