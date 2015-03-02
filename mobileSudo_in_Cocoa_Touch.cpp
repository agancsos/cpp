- (void) mobileSudo:(NSString*)cmd password:(NSString*)password{
     system([[NSString stringWithFormat:@\"echo %@|sudo -S %@\",password,cmd]UTF8String]);
}

