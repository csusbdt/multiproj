#include "stdafx.h"
#include "MPJaredMapLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"

USING_NS_CC;

bool MPJaredMapLayer::init()
{
	CCDirector * director = CCDirector::sharedDirector();

	CCSize visibleSize = director->getVisibleSize();
    CCPoint origin = director->getVisibleOrigin();

	// Back button
    CCMenuItemImage * backBtn = CCMenuItemImage::create(
		"CloseNormal.png", 
		"CloseSelected.png", 
		this, 
		menu_selector(MPJaredMapLayer::titleCallback));
	backBtn->setPosition(
		ccp(origin.x + visibleSize.width - backBtn->getContentSize().width / 2, origin.y + backBtn->getContentSize().height / 2)
	);

	// Clickable
    CCMenu * menu = CCMenu::create(backBtn, NULL);
    menu->setPosition(CCPointZero);
    addChild(menu, 1);
    
	// Screen title
    CCLabelTTF * label = CCLabelTTF::create("Jared Scene", "Arial", TITLE_FONT_SIZE);
    label->setPosition(ccp(origin.x + visibleSize.width/2,
                           origin.y + visibleSize.height - label->getContentSize().height));
    addChild(label, 1);

	CCTMXTiledMap *map = CCTMXTiledMap::create("jared_map/j_map.tmx");
    this->addChild(map, 0);

    MPJaredMapLayer::antiAliasMap(map);
        
    map->setAnchorPoint(ccp(.5, .5));
    map->setPosition(ccp(visibleSize.width * .5, visibleSize.height * .5));
    map->setScale(.5);


    CCTMXLayer* layer = map->layerNamed("Background");
    assert(layer != NULL);
    
    return true;
}

void MPJaredMapLayer::titleCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
}