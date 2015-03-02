- (NSString*)getCurrent{
	NSString* tmp=@\"\";
	tmp=[UIDevice currentDevice].systemVersion;
	return tmp;
}
