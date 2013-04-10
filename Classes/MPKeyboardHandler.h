#ifndef MP_KEYBOARD_HANDLER_H
#define MP_KEYBOARD_HANDLER_H

#include "cocos2d.h"

USING_NS_CC;

class MPKeyboardHandler
{
public:
    virtual void keyUp(char key) = 0;
    virtual void keyDown(char key) = 0;

//    virtual void aKeyUp() = 0;
//    virtual void aKeyDown() = 0;
//    virtual void wKeyUp() = 0;
//    virtual void wKeyDown() = 0;
//    virtual void sKeyUp() = 0;
//    virtual void sKeyDown() = 0;
//    virtual void dKeyUp() = 0;
//    virtual void dKeyDown() = 0;
};

#endif
