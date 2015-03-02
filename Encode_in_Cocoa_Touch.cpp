- (IBAction)encode:(id)sender{
	
	NSString* a=original.text;
	NSString* temp=@\"\";
	
	for(int i=0;i < [a length];i ++ ){
        
        
        if([a characterAtIndex:i]  ==  _)
            temp=[temp stringByAppendingString:@\"s\"];
        if([a characterAtIndex:i]  ==  a)
            temp=[temp stringByAppendingString:@\"00001\"];
        if([a characterAtIndex:i]  ==  b)
            temp=[temp stringByAppendingString:@\"00010\"];
        if([a characterAtIndex:i]  ==  c)
            temp=[temp stringByAppendingString:@\"00011\"];
        if([a characterAtIndex:i]  ==  d)
            temp=[temp stringByAppendingString:@\"00100\"];
        if([a characterAtIndex:i]  ==  e)
            temp=[temp stringByAppendingString:@\"00101\"];
        if([a characterAtIndex:i]  ==  f)
            temp=[temp stringByAppendingString:@\"00110\"];
        if([a characterAtIndex:i]  ==  g)
            temp=[temp stringByAppendingString:@\"00111\"];
        if([a characterAtIndex:i]  ==  h)
            temp=[temp stringByAppendingString:@\"01000\"];
        if([a characterAtIndex:i]  ==  i)
            temp=[temp stringByAppendingString:@\"01001\"];
        if([a characterAtIndex:i]  ==  j)
            temp=[temp stringByAppendingString:@\"01010\"];
        if([a characterAtIndex:i]  ==  k)
            temp=[temp stringByAppendingString:@\"01011\"];
        if([a characterAtIndex:i]  ==  l)
            temp=[temp stringByAppendingString:@\"01100\"];
        if([a characterAtIndex:i]  ==  m)
            temp=[temp stringByAppendingString:@\"01101\"];
        if([a characterAtIndex:i]  ==  n)
            temp=[temp stringByAppendingString:@\"01110\"];
        if([a characterAtIndex:i]  ==  o)
            temp=[temp stringByAppendingString:@\"01111\"];
        if([a characterAtIndex:i]  ==  p)
            temp=[temp stringByAppendingString:@\"10000\"];
        if([a characterAtIndex:i]  ==  q)
            temp=[temp stringByAppendingString:@\"10001\"];
        if([a characterAtIndex:i]  ==  r)
            temp=[temp stringByAppendingString:@\"10010\"];
        if([a characterAtIndex:i]  ==  s)
            temp=[temp stringByAppendingString:@\"10011\"];
        if([a characterAtIndex:i]  ==  t)
            temp=[temp stringByAppendingString:@\"10100\"];
        if([a characterAtIndex:i]  ==  u)
            temp=[temp stringByAppendingString:@\"10101\"];
        if([a characterAtIndex:i]  ==  v)
            temp=[temp stringByAppendingString:@\"10110\"];
        if([a characterAtIndex:i]  ==  w)
            temp=[temp stringByAppendingString:@\"10111\"];
        if([a characterAtIndex:i]  ==  x)
            temp=[temp stringByAppendingString:@\"11000\"];
        if([a characterAtIndex:i]  ==  y)
            temp=[temp stringByAppendingString:@\"11001\"];
        if([a characterAtIndex:i]  ==  z)
            temp=[temp stringByAppendingString:@\"11010\"];        
        
        if(i!=[a length] - 1)
            temp=[temp stringByAppendingString:@\"||\"];
    }

	[tranlated setText:[NSString stringWithFormat:@\"%@\",temp]];
}
