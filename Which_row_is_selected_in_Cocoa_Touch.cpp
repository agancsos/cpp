- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Navigation logic may go here. Create and push another view controller.
    
    UITableViewCell *selected=[tableView cellForRowAtIndexPath:indexPath];
    NSString* text=selected.textLabel.text;
    [self alert:[NSString stringWithFormat:@\"%@\",text]];

}

