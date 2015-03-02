//Create copy
- (void) createCopy{
	
	//Test
	BOOL succ;
	NSFileManager *fm=[NSFileManager defaultManager];
	NSError *failed;
	NSArray *paths=NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString *documents=[paths objectAtIndex:0];
	NSString *DBPath=[documents stringByAppendingPathComponent:@\"[name of file].sqlite\"];
	
	succ=[fm fileExistsAtPath:DBPath];
	if(succ)return;
	
	NSString *defaultPath=[[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@\"[name of file].sqlite\"];
	succ=[fm copyItemAtPath:defaultPath toPath:DBPath error:&failed];
	
	if(!succ) NSAssert1(0,@\"Failed to create database file because %s\",[failed localizedDescription]);
}

