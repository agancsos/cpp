- (void)setCopyright:(NSString*)cname{
    //This function requires a label named copy
    NSDate *date = [NSDate date];
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@\"YYYY\"];
    NSString *dateString = [dateFormat stringFromDate:date];
    copy.stringValue=[NSString stringWithFormat:@\"© %@ %@\",dateString,cname];
}

