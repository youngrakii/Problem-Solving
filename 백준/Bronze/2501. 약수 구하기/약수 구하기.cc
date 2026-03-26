#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 코드 작성
	int N,K;
	cin>>N>>K;

	vector<int> v;

	for(int i=1; i<=N; i++){
		if(N%i==0) v.push_back(i);
	}

	cout<<v[K-1]<<"\n";
	return 0;
}