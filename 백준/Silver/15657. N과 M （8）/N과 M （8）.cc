#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> nums;
vector<int> arr;

void dfs(int start, int depth){
	if(depth==M){
		for(int x:arr) cout<<x<<" ";
		cout<<"\n";
		return;
	}

	for(int i=start; i<N; i++){
		arr.push_back(nums[i]);
		dfs(i,depth+1);
		arr.pop_back();
	}
}

int main() {
	// 코드 작성
	cin>>N>>M;
	nums.resize(N);
	for(int i=0; i<N; i++) cin>>nums[i];
	sort(nums.begin(),nums.end());

	dfs(0,0);
	return 0;
}