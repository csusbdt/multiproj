#ifndef MP_JUSTIN_MAP_LAYER_H
#define MP_JUSTIN_MAP_LAYER_H

#include "cocos2d.h"
#include "MPLayer.h"

USING_NS_CC;

class MPJustinMapLayer : public MPLayer
{
public:
    CREATE_FUNC(MPJustinMapLayer);
    virtual bool init();

private:
	//static void antiAliasMap(CCTMXTiledMap * map);
    void titleCallback(CCObject * pSender);
    CCSprite * player;
};

#endif
