//
//  Entity.cpp
//  GameTest-mobile
//
//  Created by Allen on 2018/6/4.
//

#include "Entity.h"


Entity::~Entity()
{
    CCLOG("释放 pSprite");
    CC_SAFE_RELEASE_NULL(_pSprite);
}

bool Entity::init(const int &rId)
{
    if (Node::init())
    {
        bool bRet = false;
        do{
            // TODO: todo: 根据Id 去给便
            std::vector<std::string> entityVector;
            entityVector.push_back("Character_B_04_idle01_01_00.png");
            _pSprite = nullptr;
            auto sp = Sprite::createWithSpriteFrameName(entityVector.at(rId));
            bindSprite(sp);
            bRet = true;
        }while (0);
        
        return bRet;
    }
    return false;
}

const Size& Entity::getContentSize() const
{
    return _pSprite->getContentSize();
}

void Entity::bindSprite(cocos2d::Sprite *pSprite)
{
    if (_pSprite) {
        _pSprite->stopAllActions();
        removeChild(_pSprite);
    }
    CC_SAFE_RELEASE_NULL(_pSprite);
    _pSprite = pSprite;
    CC_SAFE_RETAIN(_pSprite);
    addChild(_pSprite);
}

Sprite* Entity::getSprite()
{
    return _pSprite;
}
