//
//  AppWindow.m
//  Multiproj
//
//  Created by David Turner on 4/9/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#import "AppWindow.h"
#import "MPKeyboard.h"

@implementation AppWindow

- (void)keyDown:(NSEvent *)event
{
    unichar c = [[event charactersIgnoringModifiers] characterAtIndex:0];
    if (c == 'A' || c == 'a') MPKeyboard::aDown();
    else if (c == 'W' || c == 'w') MPKeyboard::wDown();
    else if (c == 'S' || c == 's') MPKeyboard::sDown();
    else if (c == 'D' || c == 'd') MPKeyboard::dDown();
}

- (void)keyUp:(NSEvent *)event
{
    unichar c = [[event charactersIgnoringModifiers] characterAtIndex:0];
    if (c == 'A' || c == 'a') MPKeyboard::aUp();
    else if (c == 'W' || c == 'w') MPKeyboard::wUp();
    else if (c == 'S' || c == 's') MPKeyboard::sUp();
    else if (c == 'D' || c == 'd') MPKeyboard::dUp();
}

@end
