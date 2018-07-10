//
//  LoadingScene.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/4.
//

#include "LoadingScene.h"
#include "cocostudio/CocoStudio.h"
#include "GameScene.h"
#include "TestScene.h"
#include "CrashCheckScene.h"
#include "network/HttpClient.h"


using namespace network;


LoadingScene::LoadingScene():_haveLoadedNum(0),_totalNum(4)
{

}

LoadingScene::~LoadingScene()
{
    CCLOG("~LoadingScene()");
}


bool LoadingScene::init()
{
    if (Scene::init())
    {
        loadSubview();
        loadResources();
        
        
        HttpRequest* request = new  HttpRequest();
        request->setUrl("http://www.52kill.com:8080/Edit/isupdate.jsp?edition=1.1");
        request->setRequestType(HttpRequest::Type::GET);
        request->setResponseCallback([this](HttpClient* client, HttpResponse* response){
            if (response && response->isSucceed()) {
                std::vector<char> *buffer = response->getResponseData();
                std::string temp(buffer->begin(),buffer->end());
                std::string temp1(buffer->begin(),buffer->begin()+1);
                int a = std::atoi(temp1.c_str());
            }
        });
        HttpClient::getInstance()->sendImmediate(request);
        request->release();
        request = NULL;
        
        
        
        return true;
    }
    return false;
}

void LoadingScene::loadSubview()
{
    loadingLayer = CSLoader::createNode("Csb/LoadingLayer.csb");
    loadingBox = (Sprite*)loadingLayer->getChildByName("loadingBarBG");
    loadingBar = (ui::LoadingBar*)loadingBox->getChildByName("loadingBar");
    loadingBar->setPercent(0);
    
    enterBtn = (ui::Button*)loadingLayer->getChildByName("enterBtn");
    enterBtn->addClickEventListener([this](Ref* btn){
        CCLOG("GO TO GAME");
        // TODO: todo: 进入游戏
        auto scene = CrashCheckScene::create();
//        auto scene = TestScene::create();
//        auto scene = GameScene::create();
        Director::getInstance()->replaceScene(scene);
    });
    
    
    this->addChild(loadingLayer);
    
//    auto parStar = ParticleSystemQuad::create("Particle/loginparticle.plist");
//    parStar->setPosition(640, 400);
//    this->addChild(parStar,1);
    
//    auto parSmoke = ParticleSystemQuad::create("Particle/loginsmoke.plist");
//    parSmoke->setPosition(640, 180);
//    this->addChild(parSmoke,1);
    
}


void LoadingScene::onEnter()
{
    Scene::onEnter();
}


void LoadingScene::onExit()
{
    Scene::onExit();
}


void LoadingScene::loadResources()
{
    std::function<void(Texture2D*)> loadedCallback = [this](Texture2D* texture){
        _haveLoadedNum++;
        // TODO: todo:更新进度
        float percent = 100.f*(float)_haveLoadedNum/(float)_totalNum;
        CCLOG("percent  =  %f",percent);
        loadingBar->setPercent(percent);
        if (_haveLoadedNum >= _totalNum)
        {
            // 加载动画
            this->loadAnimation();
            
            // 加载完毕 可以进入游戏
            loadingBox->setVisible(false);
            enterBtn->setVisible(true);
        }
    };
    
    Director::getInstance()->getTextureCache()->addImageAsync("GameRes/Character_A_01.pvr.ccz", loadedCallback);
    Director::getInstance()->getTextureCache()->addImageAsync("GameRes/Character_B_04.pvr.ccz", loadedCallback);
    Director::getInstance()->getTextureCache()->addImageAsync("GameRes/Character_B_040.pvr.ccz", loadedCallback);
    Director::getInstance()->getTextureCache()->addImageAsync("GameRes/map.jpg", loadedCallback);
    
}



void LoadingScene::loadAnimation()
{
    // plist 文件
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameRes/Character_A_01.plist", "GameRes/Character_A_01.pvr.ccz");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameRes/Character_B_04.plist", "GameRes/Character_B_04.pvr.ccz");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameRes/Character_B_040.plist", "GameRes/Character_B_040.pvr.ccz");

    // 加载动画
    //----------------------------------------------------------------------------
    // TODO: todo: 这里注意以后需要修改成加载CSV文件
    // 得到animation的map
    auto getAnimationMap = [this](std::map<std::string,std::string> &map,const char* name,int count) {
        map.insert(std::make_pair("AnimationName", name));
        map.insert(std::make_pair("PngName", StringUtils::format("%s_0%%d.png",name)));
        map.insert(std::make_pair("totalNum", StringUtils::format("%d",count)));
    };
    
    std::vector<std::map<std::string,std::string>> csvVec;
    
    // Character_A_01.plist
    //----------------------------------------------------------------------------
    for (int i = 1; i <=3; ++i) {
        std::map<std::string,std::string> map0;
        getAnimationMap(map0, StringUtils::format("Character_A_01_Skill01_0%d",i).c_str(), 4);
        csvVec.push_back(map0);
        
        std::map<std::string,std::string> map1;
        getAnimationMap(map1, StringUtils::format("Character_A_01_attack_0%d",i).c_str(), 4);
        csvVec.push_back(map1);
        
        std::map<std::string,std::string> map2;
        getAnimationMap(map2, StringUtils::format("Character_A_01_idle_0%d",i).c_str(), 6);
        csvVec.push_back(map2);
        
        std::map<std::string,std::string> map3;
        getAnimationMap(map3, StringUtils::format("Character_A_01_move_0%d",i).c_str(), 8);
        csvVec.push_back(map3);
    }
    do {
        std::map<std::string,std::string> map4;
        map4.insert(std::make_pair("AnimationName", "Character_A_01_death_01"));
        map4.insert(std::make_pair("PngName", "Character_A_01_death_01_000%d.png"));
        map4.insert(std::make_pair("totalNum", "6"));
        csvVec.push_back(map4);
    } while (0);
    //----------------------------------------------------------------------------
    
    // Character_B_04.plist
    //----------------------------------------------------------------------------
    for (int i = 1; i <=3; ++i) {
        std::map<std::string,std::string> map0;
        getAnimationMap(map0, StringUtils::format("Character_B_04_attackS_0%d",i).c_str(), 10);
        csvVec.push_back(map0);
        
        std::map<std::string,std::string> map1;
        getAnimationMap(map1, StringUtils::format("Character_B_04_attack_0%d",i).c_str(), 10);
        csvVec.push_back(map1);
        
        std::map<std::string,std::string> map2;
        getAnimationMap(map2, StringUtils::format("Character_B_04_idle01_0%d",i).c_str(), 6);
        csvVec.push_back(map2);
        
        std::map<std::string,std::string> map21;
        getAnimationMap(map21, StringUtils::format("Character_B_04_idle02_0%d",i).c_str(), 10);
        csvVec.push_back(map21);
        
        std::map<std::string,std::string> map3;
        getAnimationMap(map3, StringUtils::format("Character_B_04_move_0%d",i).c_str(), 8);
        csvVec.push_back(map3);
    }
    do {
        std::map<std::string,std::string> map4;
        map4.insert(std::make_pair("AnimationName", "Character_B_04_death_01"));
        map4.insert(std::make_pair("PngName", "Character_B_04_death_01_000%d.png"));
        map4.insert(std::make_pair("totalNum", "6"));
        csvVec.push_back(map4);
    } while (0);
    //----------------------------------------------------------------------------
    
    // 添加动画
    for (auto map : csvVec)
    {
        int count = std::stoi(map.at("totalNum"));
        auto anim = Animation::create();
        for (int i = 0; i < count; ++i)
        {
            anim->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format(map.at("PngName").c_str(),i)));
        }
        // 播放间隔
        anim->setDelayPerUnit(1.f/(float)count);
        // 设置动画结束后是否恢复到原来的帧
        anim->setRestoreOriginalFrame(true);
        // 循环的次数  -1表示无限循环
        anim->setLoops(-1);
        AnimationCache::getInstance()->addAnimation(anim, map.at("AnimationName"));
    }
}
