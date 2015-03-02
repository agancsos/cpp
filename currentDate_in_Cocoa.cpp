- (NSString*)currentDate{
	NSDate *date = [NSDate date];
	NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
	[dateFormat setDateFormat:@\"YYYY-MM-dd\"];
	NSString *dateString = [dateFormat stringFromDate:date];
	return dateString;
}
