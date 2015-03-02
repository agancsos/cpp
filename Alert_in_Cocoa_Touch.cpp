- (void) alert:(NSString*)message{
    UIAlertView* message_;
    message_ = [[UIAlertView alloc]
               initWithTitle: @\"Reminder\"
               message: message
               delegate: nil
               cancelButtonTitle:@\"OK\"
               otherButtonTitles:nil];
    [message_ show];
    

}

