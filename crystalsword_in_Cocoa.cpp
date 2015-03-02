- (void) crystalsword{

       //IPS
       int ips1=000;
       int ips2=000;
       int ips3=000;
       int ips4=000;

       int count=0;  //Restrict value

       while(count<10){
            ips4++;

            if(ips4==255) { ips4=0;  ips3++; }
            if(ips3==255) { ips3=0; ips2++; }
            if(ips2==255) { ips2=0; ips1++; }

            [logs setText:[NSString stringWithFormat:@\"%d.%d.%d.%d\",ips1,ips2,ips3,ips4]];
            
             NSString* cmd=@\"pint -q \";
             cmd=[cmd stringByAppendingString:[NSString stringWithFormat:@\"%d.%d.%d.%d &\",ips1,ips2,ips3,ips4]];
             system([cmd UTF8String]);
            //count++;  //Mute to restrict
      }
}
