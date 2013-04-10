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

//    virtual void aKeyUp();
//    virtual void aKeyDown();
//    virtual void wKeyUp();
//    virtual void wKeyDown();
//    virtual void sKeyUp();
//    virtual void sKeyDown();
//    virtual void dKeyUp();
//    virtual void dKeyDown();
    
private:
    void titleCallback(CCObject * pSender);
    CCSprite * player;
};

#endif
