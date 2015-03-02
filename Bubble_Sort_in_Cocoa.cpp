- (void) bSort : (NSMutableArray*)a :(int) max
{
       int fin=1;
       while(fin==1)
       {
              fin=0;
              for(int i = 0; i < max - 1; i++)
              {
                   if([a objectAtIndex:j] > [a objectAtIndex:j+1])
                   {
                       int temp=[a objectAtIndex:j];
                       [a insertObject:[a objectAtIndex:j]atIndex:j];
                       [a insertObject:[temp]atIndex:j+1];
                       fin=1;
                   }
              }
       }
}
