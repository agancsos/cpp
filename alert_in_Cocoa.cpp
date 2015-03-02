- (void) alert:(NSString*)message{
    NSAlert *alert = [[[NSAlert alloc] init] autorelease];
    [alert addButtonWithTitle:@\"OK\"];
    [alert setMessageText:@\"Error....\"];
    [alert setInformativeText:message];
    [alert setAlertStyle:NSWarningAlertStyle];
    [alert beginSheetModalForWindow:_window modalDelegate:NULL didEndSelector:NULL contextInfo:NULL];    
    
}

