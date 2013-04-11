#include "stdafx.h"
#include "MPTurnerMapLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"
#include "MPKeyboard.h"

USING_NS_CC;

static float playerSpeed = 100;

void MPTurnerMapLayer::keyUp(char key)
{
}

void MPTurnerMapLayer::keyDown(char key)
{
}

void MPTurnerMapLayer::update(float dt)
{
	if (MPKeyboard::isKeyDown('w')) 
	{
		player->setPositionY(player->getPositionY() + playerSpeed * dt);
	}
	if (MPKeyboard::isKeyDown('s'))
	{
		player->setPositionY(player->getPositionY() - playerSpeed * dt);
	}
	if (MPKeyboard::isKeyDown('a')) 
	{
		player->setPositionX(player->getPositionX() - playerSpeed * dt);
	}
	if (MPKeyboard::isKeyDown('d'))
	{
		player->setPositionX(player->getPositionX() + playerSpeed * dt);
	}
    //setViewPointCenter(player->getPosition());
}

// setViewPointCenter does not work yet and is not used.
void MPTurnerMapLayer::setViewPointCenter(CCPoint position)
{
    CCDirector * director = CCDirector::sharedDirector();
    
	float h = director->getVisibleSize().height;
	float w = director->getVisibleSize().width;
    
    int x = MAX(position.x, w/2);
    int y = MAX(position.y, h/2);
    x = MIN(x, (map->getMapSize().width * map->getTileSize().width) - w / 2);
    y = MIN(y, (map->getMapSize().height * map->getTileSize().height) - h/2);
    CCPoint actualPosition = ccp(x, y);
    
    CCPoint centerOfView(w/2, h/2);
    CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
    position = viewPoint;  // don't think this is right
}

bool MPTurnerMapLayer::init()
{
    CCDirector * director = CCDirector::sharedDirector();
    
    this->setAccelerometerEnabled(true);
    this->setKeypadEnabled(true);

    CCPoint origin = director->getVisibleOrigin();

	float h = director->getVisibleSize().height;
	float w = director->getVisibleSize().width;
    
	// Back button
    CCMenuItemImage * backBtn = CCMenuItemImage::create(
		"CloseNormal.png", 
		"CloseSelected.png", 
		this, 
		menu_selector(MPTurnerMapLayer::handleBackBtn));
	backBtn->setPosition(
		ccp(origin.x + w - backBtn->getContentSize().width / 2, origin.y + backBtn->getContentSize().height / 2)
	);

	// Clickable
    CCMenu * menu = CCMenu::create(backBtn, NULL);
    menu->setPosition(CCPointZero);
    addChild(menu, 1);
    
	// Screen title
    CCLabelTTF * label = CCLabelTTF::create("Turner Scene", "Arial", TITLE_FONT_SIZE);
    label->setPosition(
        ccp(origin.x + w/2, origin.y + h - label->getContentSize().height)
    );
    addChild(label, 1);

	// Player sprite
	player = CCSprite::create("andrew_map/Player.png");
	player->setPosition(ccp(w/2, h/2));
	addChild(player, 1);
    
    CCFollow * follow = CCFollow::create(player);
    runAction(follow);
    
    MPKeyboard::setHandler(this);
    
    map = CCTMXTiledMap::create("turner_map/turner_map.tmx");
    this->addChild(map, 0);
    
    CCTMXObjectGroup * objects = map->objectGroupNamed("objects");
    CCDictionary * playerSpawnPoint = objects->objectNamed("PlayerSpawnPoint");
    float x = playerSpawnPoint->valueForKey("x")->floatValue();
    float y = playerSpawnPoint->valueForKey("y")->floatValue();
    
    // Will replace the following with call to setPlayerPosition.
    player->setPositionX(x);
    player->setPositionY(y);
    
    // May try to get the following to work.
    // See http://www.raywenderlich.com/1186/collisions-and-collectables-how-to-make-a-tile-based-game-with-cocos2d-part-2
    //setViewPointCenter(player->getPosition());

	scheduleUpdate();
    

/*
    CCSprite *tile = layer->tileAt(ccp(5,6));
    assert(tile != NULL);
    
    layer->removeTileAt(ccp(5, 6));
    
    CCActionInterval*  actionBy = CCMoveBy::create(2, ccp(visibleSize.width * .5, visibleSize.height * .5));
    map->runAction(actionBy);
    
    CCActionInterval* action = CCScaleBy::create(2, 2);
    map->runAction(action);
*/
    
    
/*
    CCSize s = layer->getLayerSize();
    for (int x = 2; x < s.width; x++) {
        for (int y = 0; y < s.height; y++) {
            layer->removeTileAt(ccp(x, y));
        }
    }
*/
    return true;
}

CCPoint MPTurnerMapLayer::tileCoordFromPosition(float posX, float posY)
{
    int x = posX / map->getTileSize().width;
    int y = ((map->getMapSize().height * map->getTileSize().height) - posY) / map->getTileSize().height;
    return ccp(x, y);
}

void MPTurnerMapLayer::setPlayerPosition(float x, float y)
{
    CCTMXLayer * collision = map->layerNamed("collision");
    CCPoint tileCoord = tileCoordFromPosition(x, y);
    
    // check that tileCoord has no collision.
    

//    CCAssert(false, "not implemented");
    assert(false);
}

void MPTurnerMapLayer::handleBackBtn(CCObject * sender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
}

