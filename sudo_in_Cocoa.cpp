- (void) sudo:(NSString*)cmd{
    cmd=[cmd stringByAppendingString:@\" with administrator privileges\"];
    NSLog(@\"%@\",cmd);

    NSAppleScript *runCMD= [[NSAppleScript alloc] initWithSource:[NSString stringWithFormat:@\"do shell script %@\",[cmd stringByReplacingOccurrencesOfString:@\"" withString:@"\"]]];
	[runCMD executeAndReturnError:nil];
}
