#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 코드 작성
	int N,K;
	cin>>N>>K;

	vector<int> arr(N);
	for(int i=0; i<N; i++){
		cin>>arr[i];
	}

	//문제에서 수의 범위는 1 이상 100000 이하
	vector<int> cnt(100001,0);

	int left=0;
	int answer=0;

	for(int right=0; right<N; right++){
		cnt[arr[right]]++;

		//현재 수가 K개를 초과하면,
		//조건을 만족할 때까지 left를 이동
		while(cnt[arr[right]]>K){
			cnt[arr[left]]--;
			left++;
		}

		//현재 구간 [left, right]는 조건을 만족
		int length = right - left +1;
		if(length>answer){
			answer = length;
		}
	}

	cout<<answer<<'\n';
	
	return 0;
}