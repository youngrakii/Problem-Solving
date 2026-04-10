#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// 코드 작성
	int N,M;
	cin>>N>>M;

	vector<int> jewel(M);

	int left=1;
	int right=0;
	int answer=0;

	for(int i=0; i<M; i++){
		cin>>jewel[i];
		right = max(right,jewel[i]);
	}

	while(left<=right){
		int mid = (left+right)/2;

		long long cnt=0;

		for(int i=0; i<M; i++){
			cnt+=jewel[i]/mid;
			if(jewel[i]%mid!=0) cnt++;
		}

		if(cnt<=N){
			answer = mid;
			right = mid-1;
		}else{
			left =mid+1;
		}


	}

	cout<<answer<<'\n';
	return 0;
}