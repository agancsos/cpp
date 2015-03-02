//
//  AppDelegate.m
//  iSmile
//
//  Created by Abel Gancsos on 5/25/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import \"AppDelegate.h\"


@implementation AppDelegate

@synthesize window = _window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
    self.window.backgroundColor=[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]];
}

- (IBAction)smile:(id)sender{
    
    NSURL *url = [NSURL fileURLWithPath:[NSString stringWithFormat:@\"%@/baby.mp3\", [[NSBundle mainBundle] resourcePath]]];
    
    NSError *error;
    player = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:&error];
    player.numberOfLoops = 0;
    [player play];
}
@end

