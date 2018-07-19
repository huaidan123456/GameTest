//
//  GDMainGameScene.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/29.
//



#include "GDMainGameScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "ALCsvUtil.h"
#include "CsvConfigDefine.h"
#include "GameRocker.h"
#include "GameRoleA.h"
#include "GameRoleCmd.h"
#include "GameRoleState.h"

#include "GameEnemyA.h"
#include "FightTestManager.h"


#include "SkillButton.h"
#include "GameRoleAITest.h"



using namespace cocos2d::ui;


GDMainGameScene::~GDMainGameScene()
{
    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
    Director::getInstance()->getTextureCache()->removeUnusedTextures();
}

void GDMainGameScene::onLoadLoading()
{
    srand((unsigned int)time(nullptr));
    auto loadLayer = CSLoader::createNode("Csb/GDLoadingLayer.csb");
    loadLayer->setName("loadLayer");
    this->addChild(loadLayer);
}

void GDMainGameScene::onLoadResources()
{
    for (int i = 1; i < 6; ++i) {
        if (i == 4) continue;// 没有20004
        int roleId = 20000 + i;
        
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_attack.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_attack_1.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_attack_2.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_attack_3.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_attack_4.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_attack_5.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_attack_effect.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_hurt.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_run.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_skill_effect.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_skill.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_stand.png",roleId,roleId));
        addImageAsync(StringUtils::format("GDGameRes/model/%d/%d_walk.png",roleId,roleId));
    }
    addImageAsync("GDGameRes/fightImg/blood.png");
    addImageAsync("GDGameRes/fightImg/role_shadow.png");
    addImageAsync("GDGameRes/fightImg/bossNoticeBg.png");
    addImageAsync("GDGameRes/fightImg/roleArrow.png");
    addImageAsync("GDGameRes/fightImg/skillBg.png");
    addImageAsync("GDGameRes/fightImg/skillNpcEffect.png");
    addImageAsync("GDGameRes/maps/40001.png");
    addImageAsync("GDGameRes/joyStick/joyStickImg.png");
    
    
    addImageAsync("GDGameRes/model/10032/10032_stand.png");
    addImageAsync("GDGameRes/model/10032/10032_hurt.png");
    addImageAsync("GDGameRes/model/10032/10032_walk.png");
    
    
    addImageAsync("GDGameRes/model/10035/10035_stand.png");
    addImageAsync("GDGameRes/model/10035/10035_hurt.png");
    addImageAsync("GDGameRes/model/10035/10035_attack.png");
    addImageAsync("GDGameRes/model/10035/10035_walk.png");
    
    
    
}

void GDMainGameScene::onLoadResourcesProgress(float percent)
{
    auto bar = (LoadingBar*) this->getChildByName("loadLayer")->getChildByName("loadbar");
    bar->setPercent(percent);
}

void GDMainGameScene::onLoadResourcesCompleted()
{
    
    ALCsvUtil::getInstance()->addFileData("GDGameRes/CSV/Animation_Role.csv");
    ALCsvUtil::getInstance()->addFileData("GDGameRes/CSV/RoleModel.csv");
    
    auto getNumStr = [](int number)->std::string{
        std::string numStr;
        if (number < 10) {
            numStr = StringUtils::format("000%d",number);
        }else if (number < 100)
        {
            numStr = StringUtils::format("00%d",number);
        }else if (number < 1000)
        {
            numStr = StringUtils::format("0%d",number);
        }else{
            numStr = StringUtils::format("%d",number);
        }
        return numStr;
    };
    
    auto sfInstance = SpriteFrameCache::getInstance();
    for (int i = 1; i < 6; ++i) {
        if (i == 4) continue;// 没有20004
        int roleId = 20000 + i;
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_attack.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_attack_1.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_attack_2.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_attack_3.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_attack_4.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_attack_5.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_attack_effect.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_hurt.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_run.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_skill_effect.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_skill.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_stand.plist",roleId,roleId));
        sfInstance->addSpriteFramesWithFile(StringUtils::format("GDGameRes/model/%d/%d_walk.plist",roleId,roleId));
        
        
        std::string csvPath = "GDGameRes/CSV/Animation_Role.csv";
        auto pCsvUtil = ALCsvUtil::getInstance();
        auto tColumnRowCount = pCsvUtil->getFileRowColNum(csvPath);
        auto tRow = std::get<1>(tColumnRowCount);
        
        
        for (int i = 1; i <= tRow; ++i) {
            auto animationName = StringUtils::format("%d%s",roleId,pCsvUtil->getText(i, CsvAnimationProperty::en_AnimationName, csvPath).c_str());
            auto frameName = StringUtils::format("%d%s",roleId,pCsvUtil->getText(i, CsvAnimationProperty::en_FrameName, csvPath).c_str());
//            auto total = pCsvUtil->getInt(i, CsvAnimationProperty::en_total, csvPath);
            auto total = 20;
            auto interval = pCsvUtil->getDouble(i, CsvAnimationProperty::en_interval, csvPath);
            
            auto animation = Animation::create();
            for (int j = 0; j < total; ++j) {
                auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("%s%s.png",frameName.c_str(),getNumStr(j).c_str()));
                if (!frame) break;
                animation->addSpriteFrame(frame);
            }
            animation->setDelayPerUnit(interval);
            animation->setRestoreOriginalFrame(true);
            
            AnimationCache::getInstance()->addAnimation(animation, animationName);
        }
    }
    sfInstance->addSpriteFramesWithFile("GDGameRes/joyStick/joyStickImg.plist");
    sfInstance->addSpriteFramesWithFile("GDGameRes/fightImg/blood.plist");
    sfInstance->addSpriteFramesWithFile("GDGameRes/fightImg/roleArrow.plist");
    sfInstance->addSpriteFramesWithFile("GDGameRes/fightImg/skillNpcEffect.plist");
    

    
    sfInstance->addSpriteFramesWithFile("GDGameRes/model/10032/10032_stand.plist");
    sfInstance->addSpriteFramesWithFile("GDGameRes/model/10032/10032_hurt.plist");
    sfInstance->addSpriteFramesWithFile("GDGameRes/model/10032/10032_walk.plist");
    
    
    sfInstance->addSpriteFramesWithFile("GDGameRes/model/10035/10035_stand.plist");
    sfInstance->addSpriteFramesWithFile("GDGameRes/model/10035/10035_hurt.plist");
    sfInstance->addSpriteFramesWithFile("GDGameRes/model/10035/10035_attack.plist");
    sfInstance->addSpriteFramesWithFile("GDGameRes/model/10035/10035_walk.plist");
    
    
    auto animation = Animation::create();
    for (int i = 0; i < 10; ++i) {
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("10032_stand_%s.png",getNumStr(i).c_str()));
        if (!frame) break;
        animation->addSpriteFrame(frame);
    }
    animation->setDelayPerUnit(0.1);
    animation->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(animation, "10032_stand");
    
    
    auto animation2 = Animation::create();
    for (int i = 0; i < 10; ++i) {
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("10032_hurt_%s.png",getNumStr(i).c_str()));
        if (!frame) break;
        animation2->addSpriteFrame(frame);
    }
    animation2->setDelayPerUnit(0.2);
    animation2->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(animation2, "10032_hurt");
    
    auto aniwalk = Animation::create();
    for (int i = 0; i < 10; ++i) {
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("10032_walk_%s.png",getNumStr(i).c_str()));
        if (!frame) break;
        aniwalk->addSpriteFrame(frame);
    }
    aniwalk->setDelayPerUnit(0.2);
    aniwalk->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(aniwalk, "10032_walk");
    
    
    
    
    // 受伤动画
    auto bloodAnim = Animation::create();
    for (int i = 0; i < 10; ++i) {
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("blood_%s.png",getNumStr(i).c_str()));
        bloodAnim->addSpriteFrame(frame);
    }
    bloodAnim->setDelayPerUnit(0.1);
    bloodAnim->setRestoreOriginalFrame(true);
    AnimationCache::getInstance()->addAnimation(bloodAnim, "blood_Animation");
}

void GDMainGameScene::onLoadScene()
{
    this->removeAllChildren();
    loadGameScene();
}



void GDMainGameScene::update(float delta)
{
    auto rockerState = pRocker->getRockerState();
    if (_pHero->getDirectionEnable() && _pHero->getActionState()->getStateID() == RoleStateDefine::StandingState && pRocker->getRockerState().getDirection() != GameRockerState::DirectionType::StayType) {
        refreshHeroDirectionState();
    }
}


void GDMainGameScene::loadGameScene()
{
    // 添加背景
    auto bg = Sprite::create("GDGameRes/maps/40001.png");
    bg->setPosition(568,320);
    this->addChild(bg);
    
    // 添加虚拟摇杆
    pRocker = GameRocker::createWithFilename("joyStickCenter.png","joyStick.png");
    pRocker->setPosition(150, 150);
    pRocker->setMovable(true);
    pRocker->setMoveRect(Rect(50, 50, 300, 300));
    pRocker->setKeysType(GameRocker::KeysType::Key_8);
    pRocker->setupDirectionStateCallback([this](const GameRockerState& rockerState){
        refreshHeroDirectionState();
    });
    this->addChild(pRocker,10);
    
    // 攻击按钮
    auto attackBtn = Button::create();//TextureResType
    attackBtn->loadTextureNormal("joyStickButton.png",Button::TextureResType::PLIST);
    attackBtn->loadTexturePressed("joyStickButtonHighLight.png",Button::TextureResType::PLIST);
    attackBtn->setPosition(Vec2(920, 200));
    attackBtn->addClickEventListener([this](Ref* btn){
        _pHero->handleInputCmd(GameRoleCmd::create(GameRoleCmd::Command::AttackCmd));
    });
    this->addChild(attackBtn,11);
    
    // 技能按钮
    auto skillBtn = SkillButton::create("joyStickskillButton.png");
    skillBtn->setSkillCoolTime(10);
    skillBtn->setPosition(1050, 120);
    skillBtn->setUpdateEnable(true);
    skillBtn->addClickCallback([this](float pressTime){
        _pHero->handleInputCmd(GameRoleCmd::create(GameRoleCmd::Command::Skill1Cmd));
    });

    skillBtn->addSkillCDEndCallback([this]{
        CCLOG(" 技能 CD 结束 ");
    });
    this->addChild(skillBtn,11);
    

    // 英雄
    CCRANDOM_0_1();
    float sj = CCRANDOM_0_1();
    int roleId = sj < 0.5 ? 20001 :20002;
    
    _pHero = GameRoleA::create(20001);
    _pHero->setPosition(Vec2(100, 100));
    this->addChild(_pHero,2);
    FightTestManager::getInstance()->addRole(_pHero);
    
    this->scheduleUpdate();
    
    
    // 添加一个敌人
    auto enemy = GameEnemyA::create(20002);
    enemy->setPosition(900, 200);
    this->addChild(enemy,1);
    
    FightTestManager::getInstance()->addEnemy(enemy);
    
    GameRoleAITest::getInstance()->start();
}


void GDMainGameScene::refreshHeroDirectionState()
{
    auto rockerState = pRocker->getRockerState();
    auto cmd = GameRoleCmd::create();
    switch (rockerState.getSpeedState()) {
        case GameRockerState::SpeedState::StayState:
            cmd->setCommand(GameRoleCmd::Command::StandingCmd);
            break;
        case GameRockerState::SpeedState::NormalState:
            cmd->setCommand(GameRoleCmd::Command::WalkingCmd);
            break;
        case GameRockerState::SpeedState::QuickState:
            cmd->setCommand(GameRoleCmd::Command::RunningCmd);
            break;
        default:
            break;
    }
    switch (rockerState.getDirection()) {
        case GameRockerState::DirectionType::StayType:
            cmd->setDirectionType(DirectionTypeDefine::NoneType);
            break;
        case GameRockerState::DirectionType::LeftType:
            cmd->setDirectionType(DirectionTypeDefine::LeftType);
            break;
        case GameRockerState::DirectionType::LeftUpType:
            cmd->setDirectionType(DirectionTypeDefine::LeftUpType);
            break;
        case GameRockerState::DirectionType::UpType:
            cmd->setDirectionType(DirectionTypeDefine::UpType);
            break;
        case GameRockerState::DirectionType::RightUpType:
            cmd->setDirectionType(DirectionTypeDefine::RightUpType);
            break;
        case GameRockerState::DirectionType::RightType:
            cmd->setDirectionType(DirectionTypeDefine::RightType);
            break;
        case GameRockerState::DirectionType::RightDownType:
            cmd->setDirectionType(DirectionTypeDefine::RightDownType);
            break;
        case GameRockerState::DirectionType::DownType:
            cmd->setDirectionType(DirectionTypeDefine::DownType);
            break;
        case GameRockerState::DirectionType::LeftDownType:
            cmd->setDirectionType(DirectionTypeDefine::LeftDownType);
            break;
        default:
            break;
    }
    _pHero->handleInputCmd(cmd);
}
