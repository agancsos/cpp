//
//  AppDelegate.m
//  Tic Tac Toe
//
//  Created by Abel Gancsos on 6/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import \"AppDelegate.h\"

@implementation AppDelegate

@synthesize window = _window;
@synthesize player_;
- (void)dealloc
{
    [super dealloc];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
    [self setCopyright:@\"Computerfox Design, LLC\"];
    player_=1;
    
    self.window.backgroundColor=[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]];
    
    p1=0;
    p2=0;
    p3=0;
    p4=0;
    p5=0;
    p6=0;
    p7=0;
    p8=0;
    p9=0;
    
    [b1 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];
    [b2 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];
    [b3 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];
    [b4 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];
    [b5 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];
    [b6 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];
    [b7 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];
    [b8 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];
    [b9 setBackgroundColor:[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]]];

    
    [b1 setImage:nil ];
    [b2 setImage:nil ];
    [b3 setImage:nil ];
    [b4 setImage:nil ];
    [b5 setImage:nil ];
    [b6 setImage:nil ];
    [b7 setImage:nil ];
    [b8 setImage:nil ];
    [b9 setImage:nil ];

}

- (void) reset{
    // Insert code here to initialize your application
    [self setCopyright:@\"Computerfox Design, LLC\"];
    player_=1;
    
    self.window.backgroundColor=[NSColor colorWithPatternImage:[NSImage imageNamed:@\"NSTexturedFullScreenBackgroundColor.png\"]];
    
    p1=0;
    p2=0;
    p3=0;
    p4=0;
    p5=0;
    p6=0;
    p7=0;
    p8=0;
    p9=0;
    
    [b1 setImage:nil ];
    [b2 setImage:nil ];
    [b3 setImage:nil ];
    [b4 setImage:nil ];
    [b5 setImage:nil ];
    [b6 setImage:nil ];
    [b7 setImage:nil ];
    [b8 setImage:nil ];
    [b9 setImage:nil ];
    
    [b1 setTitle:@\"1\"];
    [b2 setTitle:@\"2\"];
    [b3 setTitle:@\"3\"];
    [b4 setTitle:@\"4\"];
    [b5 setTitle:@\"5\"];
    [b6 setTitle:@\"6\"];
    [b7 setTitle:@\"7\"];
    [b8 setTitle:@\"8\"];
    [b9 setTitle:@\"9\"];
}

- (void)setCopyright:(NSString*)cname{
    //This function requires a label named copy
    NSDate *date = [NSDate date];
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@\"YYYY\"];
    NSString *dateString = [dateFormat stringFromDate:date];
    copy.stringValue=[NSString stringWithFormat:@\"© %@ %@\",dateString,cname];
}


- (BOOL)canBecomeFirstResponder
{ 
    return YES; 
}

- (void) alert:(NSString*)message{
    NSAlert *alert = [[[NSAlert alloc] init] autorelease];
    [alert addButtonWithTitle:@\"OK\"];
    [alert setMessageText:@\"Game Over\"];
    [alert setInformativeText:message];
    [alert setAlertStyle:NSWarningAlertStyle];
    [alert beginSheetModalForWindow:_window modalDelegate:self didEndSelector:@selector(someMethodDidEnd:returnCode:contextInfo:) contextInfo:nil];
    
    
}

- (void) again:(NSString*)message{
    NSAlert *alert = [[[NSAlert alloc] init] autorelease];
    [alert addButtonWithTitle:@\"OK\"];
    [alert setMessageText:@\"Error....\"];
    [alert setInformativeText:message];
    [alert setAlertStyle:NSWarningAlertStyle];
    [alert beginSheetModalForWindow:_window modalDelegate:NULL didEndSelector:NULL contextInfo:NULL];    
    
}

- (void) someMethodDidEnd:(NSAlert *)alert returnCode:(int)returnCode contextInfo:(void *)contextInfo
{
	if(returnCode == NSAlertFirstButtonReturn)
	{
		[self reset];
	}
}

- (void) pass:(NSAlert *)alert returnCode:(int)returnCode contextInfo:(void *)contextInfo
{
	if(returnCode == NSAlertFirstButtonReturn)
	{
        [self pass2];
	}
}


- (void) setMove: (NSString*)space{
    
    if(([space isEqualToString:@\"1\"] && (p1==1 || p1==2)) || ([space isEqualToString:@\"2\"] && (p2==1 || p2==2)) || 
([space isEqualToString:@\"3\"] && (p3==1 || p3==2)) || ([space isEqualToString:@\"4\"] && (p4==1 || p4==2)) || 
([space isEqualToString:@\"5\"] && (p5==1 || p5==2)) || ([space isEqualToString:@\"6\"] && (p6==1 || p6==2)) || 
([space isEqualToString:@\"7\"] && (p7==1 || p7==2)) || ([space isEqualToString:@\"8\"] && (p8==1 || p8==2)) || 
([space isEqualToString:@\"9\"] && (p9==1 || p9==2))){
        [self again:@\"Space is already taken...\"];
    }
    
    else{
        if([space isEqualToString:@\"1\"] && (p1!=1 || p1!=2)){
            p1=player_;
            
            if(player_==1)[b1 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b1 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
            
        }
        
        else if([space isEqualToString:@\"2\"] && (p2!=1 || p2!=2)){
            p2=player_;
            if(player_==1)[b2 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b2 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        
        else if([space isEqualToString:@\"3\"] && (p3!=1 || p3!=2)){
            p3=player_;
            if(player_==1)[b3 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b3 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"4\"] && (p4!=1 || p4!=2)){
            p4=player_;
            if(player_==1)[b4 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b4 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"5\"] && (p5!=1 || p5!=2)){
            p5=player_;
            if(player_==1)[b5 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b5 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"6\"] && (p6!=1 || p6!=2)){
            p6=player_;
            if(player_==1)[b6 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b6 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"7\"] && (p7!=1 || p7!=2)){
            p7=player_;
            if(player_==1)[b7 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b7 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"8\"] && (p8!=1 || p8!=2)){
            p8=player_;
            if(player_==1)[b8 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b8 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"9\"] && (p9!=1 || p9!=2)){
            p9=player_;
            if(player_==1)[b9 setImage:[NSImage imageNamed:@\"x.png\"] ];
            if(player_==2)[b9 setImage:[NSImage imageNamed:@\"o.png\"] ];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
            
        }
        
        
        if((p1==1 && p2==1 && p3==1) || (p4==1 && p5==1 && p6==1) || (p7==1 && p8==1 && p9==1) ||
 (p1==1 && p4==1 && p7==1) ||(p2==1 && p5==1 && p8==1) || (p3==1 && p6==1 && p9==1) || (p1==1 && p5==1 && p9==1) ||
           (p3==1 && p5==1 && p7==1)){
            [self alert:@\"Player 1 wins!!!!!\"];
        }
        
        else if((p1==2 && p2==2 && p3==2) || (p4==2 && p5==2 && p6==2) || (p7==2 && p8==2 && p9==2) || 
(p1==2 && p4==2 && p7==2) ||(p2==2 && p5==2 && p8==2) || (p3==2 && p6==2 && p9==2) || (p1==2 && p5==2 && p9==2) ||
                (p3==2 && p5==2 && p7==2)){
            [self alert:@\"Player 2 wins!!!!!\"];
        }
        
    }
    
}

- (IBAction)move1:(id)sender{
    NSString* current=@\"1\";
    [self setMove:current];
}


- (IBAction)move2:(id)sender{
    NSString* current=@\"2\";
    [self setMove:current];
}

- (IBAction)move3:(id)sender{
    NSString* current=@\"3\";
    [self setMove:current];
}

- (IBAction)move4:(id)sender{
    NSString* current=@\"4\";
    [self setMove:current];
}

- (IBAction)move5:(id)sender{
    NSString* current=@\"5\";
    [self setMove:current];
}

- (IBAction)move6:(id)sender{
    NSString* current=@\"6\";
    [self setMove:current];
}

- (IBAction)move7:(id)sender{
    NSString* current=@\"7\";
    [self setMove:current];
}

- (IBAction)move8:(id)sender{
    NSString* current=@\"8\";
    [self setMove:current];
}

- (IBAction)move9:(id)sender{
    NSString* current=@\"9\";
    [self setMove:current];
}


@end

