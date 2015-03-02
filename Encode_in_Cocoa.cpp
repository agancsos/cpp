
NSString encode: (NSString*)a{
    
    NSString temp=@\"\";
	for(int i=0;i < a.length();i ++ ){
        
        
        if(a[i]  ==  _)
        temp=[temp stringByAppendingString:@\"00000\"];			
        if(a[i]  ==  a)
        temp=[temp stringByAppendingString:@\"00001\"];			
        if(a[i]  ==  b)
        temp=[temp stringByAppendingString:@\"00010\"];			
        if(a[i]  ==  c)
        temp=[temp stringByAppendingString:@\"00011\"];			
        if(a[i]  ==  d)
        temp=[temp stringByAppendingString:@\"00100\"];			
        if(a[i]  ==  e)
        temp=[temp stringByAppendingString:@\"00101\"];			
        if(a[i]  ==  f)
        temp=[temp stringByAppendingString:@\"00110\"];			
        if(a[i]  ==  g)
        temp=[temp stringByAppendingString:@\"00111\"];			
        if(a[i]  ==  h)
        temp=[temp stringByAppendingString:@\"01000\"];			
        if(a[i]  ==  i)
        temp=[temp stringByAppendingString:@\"01001\"];			
        if(a[i]  ==  j)
        temp=[temp stringByAppendingString:@\"01010\"];			
        if(a[i]  ==  k)
        temp=[temp stringByAppendingString:@\"01011\"];			
        if(a[i]  ==  l)
        temp=[temp stringByAppendingString:@\"01100\"];			
        if(a[i]  ==  m)
        temp=[temp stringByAppendingString:@\"01101\"];			
        if(a[i]  ==  n)
        temp=[temp stringByAppendingString:@\"01110\"];			
        if(a[i]  ==  o)
        temp=[temp stringByAppendingString:@\"01111\"];			
        if(a[i]  ==  p)
        temp=[temp stringByAppendingString:@\"10000\"];			
        if(a[i]  ==  q)
        temp=[temp stringByAppendingString:@\"10001\"];			
        if(a[i]  ==  r)
        temp=[temp stringByAppendingString:@\"10010\"];			
        if(a[i]  ==  s)
        temp=[temp stringByAppendingString:@\"10011\"];			
        if(a[i]  ==  t)
        temp=[temp stringByAppendingString:@\"10100\"];			
        if(a[i]  ==  u)
        temp=[temp stringByAppendingString:@\"10101\"];			
        if(a[i]  ==  v)
        temp=[temp stringByAppendingString:@\"10110\"];			
        if(a[i]  ==  w)
        temp=[temp stringByAppendingString:@\"10111\"];			
        if(a[i]  ==  x)
        temp=[temp stringByAppendingString:@\"11000\"];			
        if(a[i]  ==  y)
        temp=[temp stringByAppendingString:@\"11001\"];			
        if(a[i]  ==  z)
        temp=[temp stringByAppendingString:@\"11010\"];			
        
        if(i!=a.length() - 1)
        temp=[temp stringByAppendingString:@\"||\"];			
    }
		    return temp;
}

