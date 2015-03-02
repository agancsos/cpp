- (NSString*) bottles99{

    NSString* final=@\"\";
    for(int i=99; i>0; i--){
              final=[final stringByAppendingString:[NSString stringWithFormat:@\"%d bottles of beer on the wall, %d bottles of beer.  You take one down, pass it around
\",i,i]]; //NOTE: CONCAT AN NSSTRING
       }

       return final;
}



//Alternate while loop

- (NSString*) bottles99{
    NSString* final=@\"\";
    int i=99;
    while(i>0){
       final=[final stringByAppendingString:[NSString stringWithFormat:@\"%d bottles of beer on the wall, %d bottles of beer.  You take one down, pass it around
\",i,i]];   

         i--;
    }


    return final;
}
