/* 
  The following is not complete on purpose
   It is meant as a template.  The rest is up to you
 */ 


//states.h


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct State{

	int ID;
	int fitness;
	int target;
	int found;

}State;

struct node
{
    //LOCKED
    State data;
    struct node *head;
    struct node *tail;
    //DO NOT ADD OR CHANGE
};



State setState (int id2, int fitness,int target,int found){

	State temp;
	temp.ID=id2;
	temp.fitness=fitness;
	temp.target=target;
	temp.found=found;
	
	return temp;

}


//.h

#import <Cocoa/Cocoa.h>
#include \"state.h\"

@interface AppDelegate : NSObject <NSApplicationDelegate>{

	int tValue;
	State temp;

}


- (IBAction)start:(id)sender;
- (IBAction)reset:(id)sender;
- (IBAction)update:(id)sender;
@property (assign) IBOutlet NSWindow *window;
@property (retain,readwrite) IBOutlet NSTextField *target;
@property (retain,readwrite) IBOutlet NSTextView *log;
@property (retain,readwrite) IBOutlet NSTextField *test;
@end


//.m

#import \"AppDelegate.h\"

@implementation AppDelegate
@synthesize target,log,test;

@synthesize window = _window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	// Insert code here to initialize your application
	
	tValue=42;
	target.stringValue=[NSString stringWithFormat:@\"%d\",tValue];
	[target setNeedsDisplay:TRUE];
	char* encoded = NULL;		
	[self encode:encoded];
}


- (IBAction)reset:(id)sender{

	tValue=42;
	target.stringValue=[NSString stringWithFormat:@\"%d\",tValue];
	log.string=@\"\";
	[target setNeedsDisplay:TRUE];
	[log setNeedsDisplay:TRUE];
	

}

- (IBAction)update:(id)sender{

	tValue=target.intValue;
	target.stringValue=[NSString stringWithFormat:@\"%d\",tValue];
	[target setNeedsDisplay:TRUE];
	temp=setState(1, 0, tValue, 0);


}

- (void) printState: (State) a{

	[log insertText:[NSString stringWithFormat:@\"
%d			 %10d 					 %10d\",a.ID,a.fitness,a.target]];
	[log setNeedsDisplay:TRUE];

}



- (IBAction)start:(id)sender{

		int state=0,fitness=0,found=0;
		char* encoded = NULL;		
		
		while (found!=1){		
			[self encode:encoded];                                     //encode
			fitness=[self decode:encoded];                            //decode
			state++;
			found=[self checker:fitness];
			temp=setState(state, fitness, tValue, found);           //set state
			[self printState:temp];
		}
		
}

- (char *) encode: (char*) a{

	char *temp = NULL;
	
	temp=\"001010100010\";
	
	test.stringValue=[NSString stringWithFormat:@\"%s\",temp];
	return temp;
}

- (int) decode: (char*) a{

	int dec=0;
	char temp[4];
	int temp1;
	int temp2;
	int flag=1;
	
	/*
	for(int i=0;a;i++){
	
		for(int j=0;j<4;j++){
			temp[j]=a[i];
		}
		
		if(flag==1){
		if(temp==\"0000\") temp1=0;		
		if(temp==\"0001\") temp1=1;
		if(temp==\"0010\") temp1=2;
		if(temp==\"0011\") temp1=3;
		if(temp==\"0100\") temp1=4;
		if(temp==\"0101\") temp1=5;
		if(temp==\"0110\") temp1=6;
		if(temp==\"0111\") temp1=7;
		if(temp==\"1000\") temp1=8;
		if(temp==\"1001\") temp1=9;
		}
		
		else if(flag>=2){
		if(temp==\"0000\") temp1=0;		
		if(temp==\"0001\") temp1=1;
		if(temp==\"0010\") temp2=2;
		if(temp==\"0011\") temp2=3;
		if(temp==\"0100\") temp2=4;
		if(temp==\"0101\") temp2=5;
		if(temp==\"0110\") temp2=6;
		if(temp==\"0111\") temp2=7;
		if(temp==\"1000\") temp2=8;
		if(temp==\"1001\") temp2=9;
		
		if(flag==2) dec+=(temp1+temp2);
		else if(flag==3) dec+=(temp1-temp2);
		else if(flag==4) dec+=(temp1*temp2);
		else if(flag==5) dec+=(temp1/temp2);
		}
		
		if(temp==\"1010\") flag=2; //+
		if(temp==\"1011\") flag=3; //-
		if(temp==\"1100\") flag=4; // *
		if(temp==\"1101\") flag=5; // divide
		
	}
*/
	return 42;


}

- (int) checker: (int) a{

	int boolean=0;
	if(tValue-a==0){
		boolean=1;
	}
	return boolean;
}



@end

