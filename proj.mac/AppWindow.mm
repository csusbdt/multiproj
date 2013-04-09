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
    if (c == 'W' || c == 'w') MPKeyboard::wDown();
}

- (void)keyUp:(NSEvent *)event
{
    unichar c = [[event charactersIgnoringModifiers] characterAtIndex:0];
    if (c == 'W' || c == 'w') MPKeyboard::wUp();
}

@end
