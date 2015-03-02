- (void) disable{
    NSString* currentOS=[[UIDevice currentDevice] systemVersion]; //Get current OS version
    NSString* cmd=[NSString stringWithFormat:@\"sed -i /s/%@/5.5.5/g /var/mobile/Library/Preferences/com.apple.springboard.plist\",currentOS]; //Set up command
    system([cmd UTF8String]);//Run command
    system([@\"killall -HUP SpringBoard\" UTF8String]); //Respring
}
