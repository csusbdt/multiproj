#include "stdafx.h"
#include "MPTurnerMapLayer.h"
#include "MPScenes.h"
#include "MPMacros.h"
#include "MPKeyboard.h"

USING_NS_CC;

#define COCOS2D_DEBUG 1

static float playerSpeed = 100;

void MPTurnerMapLayer::keyUp(char key)
{
}

void MPTurnerMapLayer::keyDown(char key)
{
}

void MPTurnerMapLayer::update(float dt)
{
    float x = player->getPositionX();
    float y = player->getPositionY();
    float dx = 0;
    float dy = 0;
	if (MPKeyboard::isKeyDown('w') && !MPKeyboard::isKeyDown('s'))
	{
		dy = 1;
	}
	else if (!MPKeyboard::isKeyDown('w') && MPKeyboard::isKeyDown('s'))
	{
		dy = -1;
	}
	if (MPKeyboard::isKeyDown('a') && !MPKeyboard::isKeyDown('d'))
	{
		dx = -1;
	}
	else if (!MPKeyboard::isKeyDown('a') && MPKeyboard::isKeyDown('d'))
	{
		dx = 1;
	}
    if (dx != 0 && dy == 0)
    {
        x += dx * playerSpeed * dt;
    }
    else if (dx == 0 && dy != 0)
    {
        y += dy * playerSpeed * dt;
    }
    else if (dx != 0 && dy != 0)
    {
        float a = sqrt((2 * playerSpeed * dt * playerSpeed * dt));
        x += dx * a;
        y += dy * a;
    }
    else
    {
        return;
    }
    setPlayerPosition(x, y);
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
    
    // I can not get the following to work:
    //    http://www.raywenderlich.com/1186/collisions-and-collectables-how-to-make-a-tile-based-game-with-cocos2d-part-2
    //setViewPointCenter(player->getPosition());

	scheduleUpdate();

    return true;
}

CCPoint MPTurnerMapLayer::tileCoordFromPosition(float posX, float posY)
{
    float x = posX / map->getTileSize().width;
    float y = posY / map->getTileSize().height;
    
//    int h = map->getMapSize().height * map->getTileSize().height;
//    int y = (h - posY) / map->getTileSize().height;
    return ccp(x, y);
}

void MPTurnerMapLayer::setPlayerPosition(float x, float y)
{
    CCPoint tileCoord = tileCoordFromPosition(x, y);
    CCTMXLayer * collision = map->layerNamed("collision");
    
    int tileId = collision->tileGIDAt(tileCoord);
    
    if (tileId != 0) return;
    
 /*
  The following does not work:
  
    CCDictionary * props = map->propertiesForGID(tileId);
    
    if (props != NULL)
    {
        const CCString * collisionValue = props->valueForKey("collidable");
        if (collisionValue == NULL)
        {
            CCLOG("collidable not defined for tile");
            assert(false);
        }
        if (collisionValue->compare("collidable") == 0)
        {
            return;
        }
    }
*/
    
    player->setPositionX(x);
    player->setPositionY(y);
}

void MPTurnerMapLayer::handleBackBtn(CCObject * sender)
{
	CCDirector::sharedDirector()->replaceScene(MPScenes::createTitleScene());
}

