#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// 코드 작성
	int T;
	cin>>T;


	while(T--){
		vector<int> v(10);
		for(int i=0; i<10; i++){
			cin>>v[i];
		}
		sort(v.rbegin(),v.rend());
		cout<<v[2]<<"\n";
	}
	return 0;
}