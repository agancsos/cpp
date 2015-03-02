NSString phlipTrans: (NSString*)a
{
      int l=[a length];
      string temp=\"\";

      for(int i=0;i<l;i++)
      {
           if ( [a objectAtIndex:i]==f)
               [temp objectAtIndex:i]=p;

           else if([a objectAtIndex:i]==p)
              [temp objectAtIndex:i]=f;


           else
               [temp objectAtIndex:i]=[a objectAtIndex:i];


       }


       return temp;
}
