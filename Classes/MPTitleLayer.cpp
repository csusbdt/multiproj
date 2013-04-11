#include "stdafx.h"
#include "MPTitleLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"

USING_NS_CC;

bool MPTitleLayer::init()
{
	CCDirector * director = CCDirector::sharedDirector();
    CCPoint origin = director->getVisibleOrigin();
	float h = director->getVisibleSize().height;
	float w = director->getVisibleSize().width;

    // Scene title
    CCLabelTTF * pLabel = CCLabelTTF::create("Title Scene", "Arial", TITLE_FONT_SIZE);
    pLabel->setPosition(
		ccp(origin.x + w/2, origin.y + h - pLabel->getContentSize().height)
	);
    this->addChild(pLabel, 1);
    
	// Layout the selectable labels.
    
	int yInc = 70;
	int xPos = w/2;
	int yPos = h - 2* yInc;
    
	// Box2D menu item label
    CCLabelTTF * box2DLabel = CCLabelTTF::create("Box 2D Scene", "Arial", TITLE_FONT_SIZE);
    box2DLabel->setPosition(CCPointZero);
    CCMenuItemLabel * box2DItem = 
		CCMenuItemLabel::create(box2DLabel, this, menu_selector(MPTitleLayer::selectBox2D));
	box2DItem->setPosition(xPos, yPos);

	// GUI Test menu item label
	yPos -= yInc;
    CCLabelTTF * guiTestLabel = CCLabelTTF::create("GUI Test Scene", "Arial", TITLE_FONT_SIZE);
    guiTestLabel->setPosition(CCPointZero);
    CCMenuItemLabel * guiTestItem = 
		CCMenuItemLabel::create(guiTestLabel, this, menu_selector(MPTitleLayer::selectGuiTest));
	guiTestItem->setPosition(xPos, yPos);
    
    // Audio Button
	yPos -= yInc;
    CCLabelTTF * audioLabel = CCLabelTTF::create("Audio Scene", "Arial", TITLE_FONT_SIZE);
    audioLabel->setPosition(CCPointZero);
    CCMenuItemLabel * audioItem = 
		CCMenuItemLabel::create(audioLabel, this, menu_selector(MPTitleLayer::selectAudio));
	audioItem->setPosition(xPos, yPos);
    
    // Map Button
	yPos -= yInc;
    CCLabelTTF * mapLabel = CCLabelTTF::create("Map Scene", "Arial", TITLE_FONT_SIZE);
    mapLabel->setPosition(CCPointZero);    
    CCMenuItemLabel * mapItem = 
		CCMenuItemLabel::create(mapLabel, this, menu_selector(MPTitleLayer::selectMap));
	mapItem->setPosition(xPos, yPos);
    
    // Turner Map Buttonog
	yPos -= yInc;
    CCLabelTTF* turnerMapLabel = CCLabelTTF::create("Turner Map Scene", "Arial", TITLE_FONT_SIZE);
    turnerMapLabel->setPosition(CCPointZero);    
    CCMenuItemLabel * turnerMapItem = 
		CCMenuItemLabel::create(turnerMapLabel, this, menu_selector(MPTitleLayer::selectTurnerMap));
	turnerMapItem->setPosition(xPos, yPos);    
    
	// Justin Map Button
	yPos -= yInc;
    CCLabelTTF* justinMapLabel = CCLabelTTF::create("Justin Map Scene", "Arial", TITLE_FONT_SIZE);
    justinMapLabel->setPosition(CCPointZero);    
    CCMenuItemLabel * justinMapItem = 
		CCMenuItemLabel::create(justinMapLabel, this, menu_selector(MPTitleLayer::selectJustinMap));
	justinMapItem->setPosition(xPos, yPos);   

	// Jared Map Button
	yPos -= yInc;
    CCLabelTTF* jaredMapLabel = CCLabelTTF::create("Jared Map Scene", "Arial", TITLE_FONT_SIZE);
    jaredMapLabel->setPosition(CCPointZero);    
    CCMenuItemLabel * jaredMapItem = 
		CCMenuItemLabel::create(jaredMapLabel, this, menu_selector(MPTitleLayer::selectJaredMap));
	jaredMapItem->setPosition(xPos, yPos);  

	// Close button
    CCMenuItemImage * closeItem = 
		CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this, menu_selector(MPTitleLayer::menuCloseCallback));
	closeItem->setPosition(
		ccp( origin.x + w - closeItem->getContentSize().width/2 ,
             origin.y + closeItem->getContentSize().height/2
		) 
	);
    
	// Menu container
    CCMenu * menu = CCMenu::create(box2DItem, guiTestItem, audioItem, mapItem, turnerMapItem, justinMapItem, jaredMapItem, closeItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);
    
    return true;
}

void MPTitleLayer::selectBox2D(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createBox2DScene());
}

void MPTitleLayer::selectGuiTest(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createGUIScene());
}

void MPTitleLayer::selectAudio(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createAudioScene());
}

void MPTitleLayer::selectMap(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createMapScene());
}

void MPTitleLayer::selectJustinMap(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createJustinMapScene());
}

void MPTitleLayer::selectTurnerMap(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTurnerMapScene());
}

void MPTitleLayer::selectJaredMap(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createJaredMapScene());
}

void MPTitleLayer::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
    exit(0);
#endif
}
