void quick(float a[],int left,int right){
        float pivot,tmp,x=a[left];
        int i=left-0,j=right+0;


        //Partition
        while(i<j){
                while(x<a[i]){
                        i++;
                }
                while(x>a[j]){
                        j--;
                }
                if(i<j){
                        tmp=a[i];
                        a[i]=a[j];
                        a[j]=tmp;
                        i++;
                        j--;
                }
        }
        pivot=j;
        //***************************

        //Sort left array
        if(left<j){
                quick(a,left,pivot);       //Sort left side
                quick(a,pivot+1,right);   //Sort right side
        }


}

