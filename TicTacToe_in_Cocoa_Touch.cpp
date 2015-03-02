//
//  ViewController.m
//  ticTacToe
//
//  Created by Abel Gancsos on 6/10/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import \"ViewController.h\"

@interface ViewController ()

@end

@implementation ViewController
@synthesize player_;

- (void)setCopyright:(NSString*)cname{
    //This function requires a label named copy
    NSDate *date = [NSDate date];
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@\"YYYY\"];
    NSString *dateString = [dateFormat stringFromDate:date];
    copy.text=[NSString stringWithFormat:@\"© %@ %@\",dateString,cname];
}

- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event
{
    if(event.type  ==  UIEventSubtypeMotionShake)
    {
        [self viewDidLoad];
    }
}

- (BOOL)canBecomeFirstResponder
{ 
    return YES; 
}

- (void) alert:(NSString*)message{
    UIAlertView* message_;
    message_ = [[UIAlertView alloc]
                initWithTitle: @\"Game Over\"
                message: message
                delegate: self
                cancelButtonTitle:@\"OK\"
                otherButtonTitles:nil];
    [message_ show];
    
    
}

- (void) again:(NSString*)message{
    UIAlertView* message_;
    message_ = [[UIAlertView alloc]
                initWithTitle: @\"Error....\"
                message: message
                delegate: nil
                cancelButtonTitle:@\"OK\"
                otherButtonTitles:nil];
    [message_ show];
    
    
}

- (void) alertView:(UIAlertView*)alertView clickedButtonAtIndex:(NSInteger)buttonIndex{  
    [self viewDidLoad];
}


- (void)viewDidLoad
{
    [super viewDidLoad];
    [self setCopyright:@\"Computerfox Design, LLC\"];
    copy.hidden=TRUE;
    player_=1;
    
    p1=0;
    p2=0;
    p3=0;
    p4=0;
    p5=0;
    p6=0;
    p7=0;
    p8=0;
    p9=0;
    
    [b1 setImage:nil forState:UIControlStateNormal];
    [b2 setImage:nil forState:UIControlStateNormal];
    [b3 setImage:nil forState:UIControlStateNormal];
    [b4 setImage:nil forState:UIControlStateNormal];
    [b5 setImage:nil forState:UIControlStateNormal];
    [b6 setImage:nil forState:UIControlStateNormal];
    [b7 setImage:nil forState:UIControlStateNormal];
    [b8 setImage:nil forState:UIControlStateNormal];
    [b9 setImage:nil forState:UIControlStateNormal];
    
    [self canBecomeFirstResponder];
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
            if(player_==1)[b1 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b1 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
            
        }
        
        else if([space isEqualToString:@\"2\"] && (p2!=1 || p2!=2)){
            p2=player_;
            if(player_==1)[b2 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b2 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        
        else if([space isEqualToString:@\"3\"] && (p3!=1 || p3!=2)){
            p3=player_;
            if(player_==1)[b3 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b3 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"4\"] && (p4!=1 || p4!=2)){
            p4=player_;
            if(player_==1)[b4 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b4 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"5\"] && (p5!=1 || p5!=2)){
            p5=player_;
            if(player_==1)[b5 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b5 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"6\"] && (p6!=1 || p6!=2)){
            p6=player_;
            if(player_==1)[b6 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b6 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"7\"] && (p7!=1 || p7!=2)){
            p7=player_;
            if(player_==1)[b7 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b7 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"8\"] && (p8!=1 || p8!=2)){
            p8=player_;
            if(player_==1)[b8 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b8 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
            if(player_==1){ player_=2;}
            else if(player_==2){ player_=1;}
        }
        else if([space isEqualToString:@\"9\"] && (p9!=1 || p9!=2)){
            p9=player_;
            if(player_==1)[b9 setImage:[UIImage imageNamed:@\"x.png\"] forState:UIControlStateNormal];
            if(player_==2)[b9 setImage:[UIImage imageNamed:@\"o.png\"] forState:UIControlStateNormal];
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

