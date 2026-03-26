#include <iostream>
#include <vector>
using namespace std;

int main() {
	// 코드 작성

	vector<int> v;
	int people=0;

	for(int i=0; i<10; i++){
		int in, out;
		cin>>out>>in;

		people-=out;
		people+=in;
		v.push_back(people);
	}

	int max=0;
	for(int i=0; i<v.size(); i++){
		if(max<v[i]) max=v[i];
	}

	cout<<max<<"\n";

	return 0;
}