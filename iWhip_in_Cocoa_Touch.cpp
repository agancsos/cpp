//
//  ViewController.m
//  iWhipped
//
//  Created by Abel Gancsos on 5/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import \"ViewController.h\"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [self becomeFirstResponder];
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}


- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event
{
    if(event.type  ==  UIEventSubtypeMotionShake)
    {
        NSURL *url = [NSURL fileURLWithPath:[NSString stringWithFormat:@\"%@/whip.mp3\", [[NSBundle mainBundle] resourcePath]]];
        
        NSError *error;
        player = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:&error];
        player.numberOfLoops = 0;
        [player play];

	}
}

- (BOOL)canBecomeFirstResponder
{ 
    return YES; 
}


@end

