#include <iostream>
#include <iomanip>
using namespace std;

void quickSort(int a[],int left,int right);
void restoreup(int a[],int i);
void restoredown(int a[],int i,int n);
char *mergeSort(char letters[], char temp[], int array_size);
char *mSort(char letters[], char temp[], int left, int right);
char *merge(char letters[], char temp[], int left, int mid, int right);
void charBubbleSort(char a[],int max);
void bubbleSort(int a[],int max);

void restoreup(int a[],int i)
{
	int value=a[i];
	
	while((i>1)&&(a[i/2]<value))
	{
		a[i]=a[i/2];
		i=i/2;
	}
	
	a[i]=value;
}

void restoredown(int a[],int i,int n)
{
	int value=a[i],j=i*2;
	
	while(j<=n)
	{
		if((j<n)&&(a[j]<a[j+1]))
			j++;
		
		if(a[j]<a[j/2])
			break;
		
		a[j/2]=a[j];
		j=j*2;
	}
	
	a[j/2]=value;
}

void quickSort(int a[],int left,int right){
	int pivot=a[(left+right)/2],tmp;
	int i=left,j=right;
	
	while(i<=j){
        while(a[i]<pivot){
			i++;
        }
        while(a[j]>pivot){
			j--;
        }
        
        if(i<=j){
			tmp=a[i];
			a[i]=a[i+1];
			a[i+1]=tmp;
			i++;
			j--;
		}
	}
	
	if(left<j)
		quickSort(a,left,j);
	
	if(i<right)
		quickSort(a,i,right);
	
	//return a;
}

char *mergeSort(char letters[], char temp[], int array_size)
{
    return mSort( letters, temp, 0, array_size - 1);
}


char *mSort(char letters[], char temp[], int left, int right)
{
    int mid;
    
    if (right > left)
    {
        mid = (right + left) / 2;
        mSort( letters, temp, left, mid);
        mSort( letters, temp, (mid+1), right);
        
        merge( letters, temp, left, (mid+1), right);
    }
    
    return letters;
}

char *merge(char letters[], char temp[], int left, int mid, int right)
{
    int i, leftEnd, elements, tmpPos;
    
    leftEnd = (mid - 1);
    tmpPos = left;
    elements = (right - left + 1);
    
    while ((left <= leftEnd) && (mid <= right))
    {
        if ( letters[left] <=  letters[mid])
        {
            temp[tmpPos] =  letters[left];
            tmpPos += 1;
            left += 1;
        }
        else
        {
            temp[tmpPos] =  letters[mid];
            tmpPos += 1;
            mid += 1;
        }
    }
    
    while (left <= leftEnd)
    {
        temp[tmpPos] =  letters[left];
        left += 1;
        tmpPos += 1;
    }
    while (mid <= right)
    {
        temp[tmpPos] =  letters[mid];
        mid += 1;
        tmpPos += 1;
    }
    
    for (i=0; i < elements; i++)
    {
        letters[right] = temp[right];
        right -= 1;
    }
    
    return temp;
}

void bubbleSort(int a[],int max){
	
	for(int i=0;i<max-1;i++){
		for(int j=0;j<max-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void charBubbleSort(char a[],int max){
	
	for(int i=0;i<max-1;i++){
		for(int j=0;j<max-1;j++){
			if(a[j]>a[j+1]){
				char temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

