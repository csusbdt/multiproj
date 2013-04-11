#ifndef MP_TURNER_MAP_LAYER_H
#define MP_TURNER_MAP_LAYER_H

#include "cocos2d.h"
#include "MPLayer.h"
#include "MPKeyboardHandler.h"

USING_NS_CC;

class MPTurnerMapLayer : public MPLayer, public MPKeyboardHandler
{
public:
    CREATE_FUNC(MPTurnerMapLayer);
    virtual bool init();

    virtual void keyUp(char key);
    virtual void keyDown(char key);

	virtual void update(float delta);

private:
    void titleCallback(CCObject * pSender);
    CCSprite * player;
    CCTMXTiledMap * map;
    void setViewPointCenter(CCPoint position);
};

#endif
