- (NSString*) getVersion{
     return [[[NSBundle mainBundle]infoDictionary]objectForKey:@\"CFBundleShortVersionString\"];
}

