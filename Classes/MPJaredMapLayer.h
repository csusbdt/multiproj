#ifndef MP_JARED_MAP_LAYER_H
#define MP_JARED_MAP_LAYER_H

#include "cocos2d.h"
#include "MPLayer.h"

USING_NS_CC;

class MPJaredMapLayer : public MPLayer
{
public:
    CREATE_FUNC(MPJaredMapLayer);
    virtual bool init();

private:
    void titleCallback(CCObject * pSender);
};

#endif
