//
//  ALSceneExtension.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/29.
//

#include "ALSceneExtension.h"


ALSceneExtension::~ALSceneExtension()
{
    CCLOG("~ALSceneExtension()");
}


bool ALSceneExtension::init()
{
    if (Scene::init()) {
        
        onLoadLoading();
        return true;
    }
    return false;
}

void ALSceneExtension::onEnter()
{
    Scene::onEnter();
    CCLOG("ALSceneExtension::onEnter()");
    onLoadResources();
    loadImageAsync();
    if (_imagepathVector.size() == 0) {
        onLoadResourcesCompleted();
        onLoadScene();
    }
}

void ALSceneExtension::onExit()
{
    Scene::onExit();
    CCLOG("ALSceneExtension::onExit()");
    
}


void ALSceneExtension::onLoadLoading()
{
    
}

void ALSceneExtension::onLoadResources()
{
    
}
void ALSceneExtension::onLoadResourcesProgress(float percent)
{
    
}
void ALSceneExtension::onLoadResourcesCompleted()
{
    
}
void ALSceneExtension::onLoadScene()
{

}
void ALSceneExtension::onEnterScene()
{
    
}
void ALSceneExtension::onExitScene()
{
    
}


void ALSceneExtension::addImageAsync(const std::string &filepath)
{
    _imagepathVector.push_back(filepath);
}


const ALSceneExtension::alAddImageCallback& ALSceneExtension::getAddImageCallback()
{
    if (!_addImageCallback) {
        _addImageCallback = [this](Texture2D* texture){
            _loadedImageCount++;
            float percent = 100.f*(float)_loadedImageCount/(float)_imagepathVector.size();
            this->onLoadResourcesProgress(percent);
            if (_loadedImageCount >= _imagepathVector.size()) {
                this->onLoadResourcesCompleted();
                this->onLoadScene();
            }
        };
    }
    return _addImageCallback;
}

void ALSceneExtension::loadImageAsync()
{
    if (_imagepathVector.size() > 0) {
        for (auto imagepath:_imagepathVector) {
            Director::getInstance()->getTextureCache()->addImageAsync(imagepath, getAddImageCallback());
        }
    }
}

void ALSceneExtension::removeAllResourcesCache()
{
    
}
