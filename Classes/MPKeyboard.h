#ifndef  _MP_KEYBOARD_H_
#define  _MP_KEYBOARD_H_

#include "cocos2d.h"
#include "MPKeyboardHandler.h"

/**
@brief    Keyboard events.

Platform specific code sends keyboard events here.
*/
class  MPKeyboard 
{
public:
	static void aUp();
	static void aDown();
	static void wUp();
	static void wDown();
	static void sUp();
	static void sDown();
	static void dUp();
	static void dDown();

	static bool isKeyDown(char c);

    static void setHandler(MPKeyboardHandler * handler);

private:
	static bool isAUp;
	static bool isWUp;
	static bool isSUp;
	static bool isDUp;

    static MPKeyboardHandler * handler;
};

#endif