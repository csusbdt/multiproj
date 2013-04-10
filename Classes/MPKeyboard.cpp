#include "stdafx.h"
#include "MPKeyboard.h"

USING_NS_CC;
using namespace std;

// We need to keep track of whether the key is up because of key repeat.

MPKeyboardHandler * MPKeyboard::handler = NULL;

bool MPKeyboard::isAUp = true;
bool MPKeyboard::isWUp = true;
bool MPKeyboard::isSUp = true;
bool MPKeyboard::isDUp = true;

void MPKeyboard::setHandler(MPKeyboardHandler * handler)
{
    MPKeyboard::handler = handler;
}

void MPKeyboard::aUp()
{
	isAUp = true;
    if (MPKeyboard::handler != NULL) MPKeyboard::handler->keyUp('a');
}

void MPKeyboard::aDown()
{
	if (isAUp)
	{
		isAUp = false;
        if (MPKeyboard::handler != NULL) MPKeyboard::handler->keyDown('a');
	}
}

void MPKeyboard::wUp()
{
	isWUp = true;
    if (MPKeyboard::handler != NULL) MPKeyboard::handler->keyUp('w');
}

void MPKeyboard::wDown()
{
	if (isWUp)
	{
		isWUp = false;
        if (MPKeyboard::handler != NULL) MPKeyboard::handler->keyDown('w');
	}
}

void MPKeyboard::sUp()
{
	isSUp = true;
    if (MPKeyboard::handler != NULL) MPKeyboard::handler->keyUp('s');
}

void MPKeyboard::sDown()
{
	if (isSUp)
	{
		isSUp = false;
        if (MPKeyboard::handler != NULL) MPKeyboard::handler->keyDown('s');
	}
}

void MPKeyboard::dUp()
{
	isDUp = true;
    if (MPKeyboard::handler != NULL) MPKeyboard::handler->keyUp('d');
}

void MPKeyboard::dDown()
{
	if (isDUp)
	{
		isDUp = false;
        if (MPKeyboard::handler != NULL) MPKeyboard::handler->keyDown('d');
	}
}
