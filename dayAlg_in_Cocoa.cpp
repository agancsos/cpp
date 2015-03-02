- (int) dayAlg: (int) month:(int)day{
    int temp2;
    
    if(month==1) temp2=0;
    else if(month==2) temp2=31;
    else if(month==3) temp2=60;
    else if(month==4) temp2=91;
    else if(month==5) temp2=121;
    else if(month==6) temp2=152;
    else if(month==7) temp2=182;
    else if(month==8) temp2=213;
    else if(month==9) temp2=244;
    else if(month==10) temp2=274;
    else if(month==11) temp2=305;
    else if(month==12) temp2=335;
    
    temp2+=(day-1);
    
    return temp2;
}

