- (NSString*)stringToLower:(NSString*)a{
     NSString* tmp=@\"\";
     for(int i=0;i<[a length];i++){
          if([a characterAtIndex:i]==A){
               tmp=[tmp stringByAppendingString:@\"a\"];
          }
          else if([a characterAtIndex:i]==B){
               tmp=[tmp stringByAppendingString:@\"b\"];
          }
          else if([a characterAtIndex:i]==C){
               tmp=[tmp stringByAppendingString:@\"c\"];
          }
          else if([a characterAtIndex:i]==D){
               tmp=[tmp stringByAppendingString:@\"d\"];
          }
          else if([a characterAtIndex:i]==E){
               tmp=[tmp stringByAppendingString:@\"e\"];
          }
          else if([a characterAtIndex:i]==F){
               tmp=[tmp stringByAppendingString:@\"f\"];
          }
          else if([a characterAtIndex:i]==G){
               tmp=[tmp stringByAppendingString:@\"g\"];
          }
          else if([a characterAtIndex:i]==H){
               tmp=[tmp stringByAppendingString:@\"h\"];
          }
          else if([a characterAtIndex:i]==I){
               tmp=[tmp stringByAppendingString:@\"i\"];
          }
          else if([a characterAtIndex:i]==J){
               tmp=[tmp stringByAppendingString:@\"j\"];
          }
          else if([a characterAtIndex:i]==K){
               tmp=[tmp stringByAppendingString:@\"k\"];
          }
          else if([a characterAtIndex:i]==L){
               tmp=[tmp stringByAppendingString:@\"l\"];
          }
          else  if([a characterAtIndex:i]==M){
               tmp=[tmp stringByAppendingString:@\"m\"];
          }
          else if([a characterAtIndex:i]==N){
               tmp=[tmp stringByAppendingString:@\"n\"];
          }
          else if([a characterAtIndex:i]==O){
               tmp=[tmp stringByAppendingString:@\"o\"];
          }
          else if([a characterAtIndex:i]==P){
               tmp=[tmp stringByAppendingString:@\"p\"];
          }
          else if([a characterAtIndex:i]==Q){
               tmp=[tmp stringByAppendingString:@\"q\"];
          }
          else if([a characterAtIndex:i]==R){
               tmp=[tmp stringByAppendingString:@\"r\"];
          }
          else if([a characterAtIndex:i]==S){
               tmp=[tmp stringByAppendingString:@\"s\"];
          }
          else if([a characterAtIndex:i]==T){
               tmp=[tmp stringByAppendingString:@\"t\"];
          }
          else if([a characterAtIndex:i]==U){
               tmp=[tmp stringByAppendingString:@\"u\"];
          }
          else if([a characterAtIndex:i]==V){
               tmp=[tmp stringByAppendingString:@\"v\"];
          }
          else if([a characterAtIndex:i]==W){
               tmp=[tmp stringByAppendingString:@\"w\"];
          }
          else if([a characterAtIndex:i]==X){
               tmp=[tmp stringByAppendingString:@\"x\"];
          }
          else if([a characterAtIndex:i]==Y){
               tmp=[tmp stringByAppendingString:@\"y\"];
          }
          else if([a characterAtIndex:i]==Z){
               tmp=[tmp stringByAppendingString:@\"z\"];
          }
          else{
               tmp=[tmp stringByAppendingString:[NSString stringWithFormat:@\"%c\",[a characterAtIndex:i]]];
          }
     }
     
     return tmp;
}
