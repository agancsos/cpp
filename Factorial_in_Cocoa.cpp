- (double) factorial :(double a{
    int value=1;
    if(a==0)
        return 1;
    
    for(int i=1;i<=a;i++){
        value*=i;
    }
    return value;
                        
}
