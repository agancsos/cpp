void quick:(NSMutableArray*):a left:(int)left right:(int)right{
        float pivot,tmp,x=[a objectAtIndex:left];
        int i=left-0,j=right+0;


        //Partition
        while(i<j){
                while(x<[a objectAtIndex:i]){
                        i++;
                }
                while(x>[a objectAtIndex[j]){
                        j--;
                }
                if(i<j){
                        tmp=[a objectAtIndex[i];
                        [a insertObject:[a objectAtIndex:j]atIndex:i];
                        [a insertObject:tmp atIndex:j];
                        i++;
                        j--;
                }
        }
        pivot=j;
        //***************************

        //Sort left array
        if(left<j){
                [self quick:a left:left right:pivot];            //Sort left side
                [self quick:a left:pivot+1 right: right];   //Sort right side
        }


}

