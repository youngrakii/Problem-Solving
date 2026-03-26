#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// 코드 작성
	int N;
	cin>>N;
	
	vector<int> v;
	for(int i=0; i<N; i++){
		int k;
		cin>>k;
		v.push_back(k);
	}

	sort(v.begin(),v.end());

	cout<<v[0]<<" "<<v[N-1]<<"\n";
	return 0;
}