#include <iostream>
#include <vector>
using namespace std;

int main() {
	// 코드 작성
	int M,N;
	cin>>M>>N;

	vector<int> v;

	for(int i=M; i<=N; i++){
		int cnt=0;
		for(int j=1; j<=i; j++){
			if(i%j==0){
				cnt++;
			}
		}
		if(cnt==2) v.push_back(i);
	}

	int sum=0;

	if(!v.empty()){
		for(int i=0; i<v.size(); i++){
			sum+=v[i];
		}

		cout<<sum<<"\n";
		cout<<v[0]<<"\n";

	}
	else cout<<"-1"<<"\n";


	return 0;
}