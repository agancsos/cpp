- (int) gcd: (int) num1 num2:(int) num2{
int temp;
if(num1>num2)  
       m=num2;  
   else  
       m=num1;  
   for(i=m;i>=1;i--)  
   {  
       if(num1%i==0&&num2%i==0)  
       {  
         temp=1; ;  
         break;  
       }  
   }

   return temp;
}
