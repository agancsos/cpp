#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <memory>
using namespace std;

class GiftPair {
	public:
        string fromName;
        string toName;
		GiftPair() {
		}
		~GiftPair() {
		}
};

shared_ptr<GiftPair> generatePair(string name, vector<shared_ptr<GiftPair> > pairs, vector<string> names) {
	shared_ptr<GiftPair> result = nullptr;
	while(result == nullptr) {
		result = shared_ptr<GiftPair>(new GiftPair());
		result->fromName = name;
		result->toName = names[rand() % names.size()];
		for(shared_ptr<GiftPair> cursor : pairs) {
			if(cursor->toName == result->fromName) {
				cursor = nullptr;
			}
		}
	}
	return result; 	
}

int main(int argc, char **argv) {
	srand(time(NULL));
    vector<shared_ptr<GiftPair> > pairs;
	vector<string> names;

	for(int i = 0; i < names.size(); i++) {
		shared_ptr<GiftPair> newPair = generatePair(names[i], pairs, names);
		pairs.push_back(newPair);
	}

	for(shared_ptr<GiftPair> cursor : pairs) {
		printf("%s => %s \n", cursor->fromName.c_str(), cursor->toName.c_str());
	}
	printf("\n");
	return 0;
}
