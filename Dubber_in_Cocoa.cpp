//.h

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>{

	IBOutlet NSTextField *mins;
	IBOutlet NSTextField *format;
	



}

- (IBAction)calc:(id)sender;
- (IBAction)reset:(id)sender;

@property (assign) IBOutlet NSWindow *window;

@end


//.m


#import \"AppDelegate.h\"

@implementation AppDelegate

@synthesize window = _window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	// Insert code here to initialize your application
}

- (IBAction)reset:(id)sender{

	mins.stringValue=@\"\";
	format.stringValue=@\"\";
	[mins setNeedsDisplay:TRUE];
	[format setNeedsDisplay:TRUE];


}

- (IBAction)calc:(id)sender{

	double minutes=0;
	double tapes=0;
	
	minutes=mins.doubleValue;
	tapes=format.doubleValue;
	
	if(minutes>0 && tapes>0){ mins.stringValue=@\"ERROR\"; format.stringValue=@\"ERROR\";}
	
	else if(minutes==0 && tapes==0){ mins.stringValue=@\"ERROR\"; format.stringValue=@\"ERROR\";}
	
	else if(minutes>0 && tapes==0){
	
		minutes/=60;
		
		if(minutes<=1.15)
			format.stringValue=@\"1 hr\";
			
		else if(minutes>1 && minutes<2.25)
			format.stringValue=@\"2 hrs\";

		else if(minutes>=2.25 && minutes<3)
			format.stringValue=@\"2.5 hrs\";
			
		else if(minutes>=3 && minutes<4)
			format.stringValue=@\"3 hrs\";
		
		else if(minutes>=4 && minutes<4.25)
			format.stringValue=@\"4 hrs\";
		
		else if(minutes>=4.25 && minutes<6.25)
			format.stringValue=@\"6 hrs\";

		else{
			format.stringValue=@\"ERROR\";
		}
	}
	
}

@end


//Simple, but very useful
