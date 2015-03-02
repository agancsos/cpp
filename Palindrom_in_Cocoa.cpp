//
//  AppDelegate.m
//  pals
//
//  Created by Abel Gancsos on 3/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import \"AppDelegate.h\"

@implementation AppDelegate

@synthesize window = _window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    [input insertText:[NSString stringWithFormat:@\"Enter paragraph to flip\"]];
}

- (IBAction)translate:(id)sender{
    
    NSString *temp=input.string;
    
    for(int i=temp.length;i>=0;i--){
        [output insertText:[NSString stringWithFormat:@\"%c\",[temp characterAtIndex:i-1]]];


    }
    
}

- (IBAction)clear:(id)sender{
    [input setString:@\"Enter paragraph to flip\"];
    [output setString:@\"\"];
    [input setNeedsDisplay:TRUE];
    [output setNeedsDisplay:TRUE];

}
@end

