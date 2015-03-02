//
//  mycanvas.m
//  artPad
//
//  Created by Abel Gancsos on 5/9/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import \"mycanvas.h\"
#import <QuartzCore/QuartzCore.h>
#import \"ViewController.h\"

@implementation mycanvas
@synthesize path,x,y,mouseSwipped,color;

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
	
	colors_.selectedSegmentIndex=8;
    return self;
}

//Initial
-(void)touchBegan {
    path = CGPathCreateMutable();
}


//Moved line
-(void)touchMoved {
    CGPathMoveToPoint(path,NULL,x,y);
    CGPathAddLineToPoint(path,NULL,x,y);

}


//Touched screen
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
 
	mouseSwipped = NO;
	UITouch *touch = [touches anyObject];
 
	if([touch tapCount]==3){
	
		
		self.image = nil;
		return;
	}
 
	lastPoint = [touch locationInView:self];
	lastPoint.y -= 10;
 
}

//Draw line
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
	mouseSwipped = YES;
 
	UITouch *touch = [touches anyObject];
	CGPoint currentPoint = [touch locationInView:self];
	currentPoint.y -= 10;
 
 
	UIGraphicsBeginImageContext(self.frame.size);
	[self.image drawInRect:CGRectMake(0, 0, self.frame.size.width, self.frame.size.height)];
	CGContextSetLineCap(UIGraphicsGetCurrentContext(), kCGLineCapRound);
	CGContextSetLineWidth(UIGraphicsGetCurrentContext(), 5.0);
	
		CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 0.0, 0.0, 0.0, 1.0);
	
	if(colors_.selectedSegmentIndex==0)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 0.0, 0.0, 1.0);//r
	if(colors_.selectedSegmentIndex==1)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 0.3, 0.1, 1.0);//o
	if(colors_.selectedSegmentIndex==2)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 1.0, 0.0, 1.0);//y
	if(colors_.selectedSegmentIndex==3)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 0.0, 0.4, 0.4, 1.0);//g
	if(colors_.selectedSegmentIndex==4)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 0.0, 0.6, 6.0, 1.0);//b
	if(colors_.selectedSegmentIndex==5)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 0.3, 0.5, 1.0);//i
	if(colors_.selectedSegmentIndex==6)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 0.5, 1.0, 1.0);//v

	if(colors_.selectedSegmentIndex==7)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 0.0, 0.0, 0.0, 1.0);//b;


	CGContextBeginPath(UIGraphicsGetCurrentContext());
	CGContextMoveToPoint(UIGraphicsGetCurrentContext(), lastPoint.x, lastPoint.y);
	CGContextAddLineToPoint(UIGraphicsGetCurrentContext(), currentPoint.x, currentPoint.y);
	CGContextStrokePath(UIGraphicsGetCurrentContext());
	self.image = UIGraphicsGetImageFromCurrentImageContext();
	UIGraphicsEndImageContext();
 
	lastPoint = currentPoint;
 
}

//End line
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
 
	UITouch *touch = [touches anyObject];
  
	if([touch tapCount]==3){
	
		self.image = nil;
		return;
	}
 
	if(!mouseSwipped) {
		UIGraphicsBeginImageContext(self.frame.size);
		[self.image drawInRect:CGRectMake(0, 0, self.frame.size.width, self.frame.size.height)];
		CGContextSetLineCap(UIGraphicsGetCurrentContext(), kCGLineCapRound);
		CGContextSetLineWidth(UIGraphicsGetCurrentContext(), 5.0);
		
		CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 0.0, 0.0, 0.0, 1.0);
		
		if(colors_.selectedSegmentIndex==0)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 0.0, 0.0, 1.0);//r
		if(colors_.selectedSegmentIndex==1)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 0.3, 0.1, 1.0);//o
		if(colors_.selectedSegmentIndex==2)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 1.0, 0.0, 1.0);//y
		if(colors_.selectedSegmentIndex==3)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 0.0, 0.4, 0.4, 1.0);//g
		if(colors_.selectedSegmentIndex==4)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 0.0, 0.6, 6.0, 1.0);//b
		if(colors_.selectedSegmentIndex==5)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 0.3, 0.5, 1.0);//i
		if(colors_.selectedSegmentIndex==6)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 1.0, 0.5, 1.0, 1.0);//v
		
		if(colors_.selectedSegmentIndex==7)CGContextSetRGBStrokeColor(UIGraphicsGetCurrentContext(), 0.0, 0.0, 0.0, 1.0);//b;

		CGContextMoveToPoint(UIGraphicsGetCurrentContext(), lastPoint.x, lastPoint.y);
		CGContextAddLineToPoint(UIGraphicsGetCurrentContext(), lastPoint.x, lastPoint.y);
		CGContextStrokePath(UIGraphicsGetCurrentContext());
		CGContextFlush(UIGraphicsGetCurrentContext());
		self.image = UIGraphicsGetImageFromCurrentImageContext();
		UIGraphicsEndImageContext();
	}
}

@end

