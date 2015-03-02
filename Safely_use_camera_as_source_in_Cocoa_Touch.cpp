- (IBAction)takePic:(id)sender{
    if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
    UIImagePickerController *picker = [[UIImagePickerController alloc] init];
    picker.delegate = self;
	picker.sourceType = UIImagePickerControllerSourceTypeCamera;
	picker.allowsEditing = YES;
	
	[self presentModalViewController:picker animated:YES];
    }
    
    else{
        matched_.text=@\"You are running on a simulator....\";
    }
    
}

