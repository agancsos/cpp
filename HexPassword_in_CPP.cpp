#include <iostream>
using namespace std;

int main(){

	string pass=\"\";
	string chars[]={\"0\",\"1\",\"2\",\"3\",\"4\",\"5\",\"6\",\"7\",\"8\",\"9\",\"a\",\"b\",\"c\",\"d\",
			\"e\",\"f\"};

	int max,again=1;

	while(again==1){
	cout<<\"Enter numeric value for max characters: \";
	cin>>max;

	for(int i=0;i<max;i++){
		pass+=chars[rand()%6+1+1];
	}

	cout<<\"Copy this password down: \"<<pass<<endl;

	cout<<\"1-Again  2-Close: \";
	cin>>again;

	}

	return 0;
}

