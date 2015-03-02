#include <iostream>
#include <string>
using namespace std;


string merge(string,string,int);
string mergeSort(string);
string rest(int,int,string);

string rest(int from,int to,string phrase){
	string temp;
	
	for(int i=from;i<=to;i++){
		temp[i-1]=phrase[i];
	}
	return temp;
}
string merge(string left,string right,int max){
	string result;
    while (left.length() > 0 || right.length() > 0 ){
        if (left.length() > 0 && right.length() > 0){
			if (left[0] <= right[0]){
                result+=left[0];
                left= rest(1,left.length(),left);
			}
			if(left[0]>right[0])
			    {
				result+=right[0];
				right= rest(1,right.length(),right);
			}
				if (left.length() > 0){
					result+= left[0];
					left= rest(1,left.length(),left);
				}
				if (right.length() > 0){
					
				    result+=right[0];
					right= rest(1,right.length(),right);
				}
			}
		}
	return result;	
}
string mergeSort(string a){
	if(a.length()<=1)
		return a;
	
    int max=a.length();
	string left,right,result;
	int middle=(a.length())/2;
	
	for(int i=0;i<max;i++){
		if(i<middle)
		  left+=a[i];
		else 
			if(i>=middle)
			right+=a[i];

	}
	left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right,max);
    return result+left;
}

	

