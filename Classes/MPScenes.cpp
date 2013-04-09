#include "stdafx.h"
#include "MPScenes.h"
#include "MPMacros.h"
#include "MPScenes.h"
#include "MPTitleLayer.h"
#include "MPMapLayer.h"
#include "MPTurnerMapLayer.h"
#include "MPJustinMapLayer.h"
#include "MPJaredMapLayer.h"
#include "MPGuiTestLayer.h"
#include "MPBox2DLayer.h"
#include "MPAudioLayer.h"

USING_NS_CC;

cocos2d::CCScene * MPScenes::createTitleScene(){
   	CCScene *scene = CCScene::create();
	CCLayer *layer = MPTitleLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createMapScene(){
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPMapLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createJustinMapScene(){
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPJustinMapLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createTurnerMapScene(){
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPTurnerMapLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createJaredMapScene(){
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPJaredMapLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createAudioScene(){
    CCScene *scene = CCScene::create();
    CCLayer *layer = MPAudioLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createBox2DScene(){
    CCScene *scene = CCScene::create();
	CCLayer * layer = MPBox2DLayer::create();
    scene->addChild(layer);
    return scene;
}

cocos2d::CCScene * MPScenes::createGUIScene(){
    CCScene *scene = CCScene::create();
	CCLayer * layer = MPGuiTestLayer::create();
    scene->addChild(layer);
    return scene;
}