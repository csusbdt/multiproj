//
//  AppWindow.h
//  Multiproj
//
//  Created by David Turner on 4/9/13.
//  Copyright (c) 2013 Bullets in a Burning Box, Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

//#import "cocos2d.h"
//#import "EAGLView.h"

@interface AppWindow : NSWindow

- (void)keyDown:(NSEvent *)event;
- (void)keyUp:(NSEvent *)event;

@end
