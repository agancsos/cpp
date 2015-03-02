- (void)alertMessage:(NSString*)message title:(NSString*)title fontSize:(int)fontSize{    
    NSAlert *alert = [[NSAlert alloc] init];
    [alert addButtonWithTitle:@\"Close\"];
    [alert setAlertStyle:NSWarningAlertStyle];
    [alert setDelegate:NULL];
    [alert setMessageText:title];
    NSArray* views = [[[alert window] contentView] subviews]; 
    NSFont *titleFont = [NSFont fontWithName:@\"Arial\" size:fontSize+2];
    [[views objectAtIndex:4]setFont:titleFont];
    NSFont *font = [NSFont fontWithName:@\"Arial\" size:fontSize];
    [[views objectAtIndex:5]setFont:font];
    [alert setInformativeText:[NSString stringWithFormat:@\"%@\",message]];
    [alert beginSheetModalForWindow:_window modalDelegate:self didEndSelector:NULL contextInfo:NULL];   
}

