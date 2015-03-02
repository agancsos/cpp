- (NSString*) getCopyright{
    NSDate *date = [NSDate date];
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@\"YYYY\"];
    NSString *dateString = [dateFormat stringFromDate:date];
    
    return dateString;
}
