#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int N,M;
vector<int> nums;
vector<int> arr;
bool visited[9];

void dfs(int start, int depth){
	if(depth==M){
		for(int x:arr) cout<<x<<" ";
		cout<<"\n";
		return;
	}

	int prev=-1;

	for(int i=start; i<N; i++){
		if(visited[i]) continue;
		if(nums[i]==prev) continue;

		visited[i]=true;
		arr.push_back(nums[i]);
		prev = nums[i];
		dfs(i+1,depth+1);
		arr.pop_back();
		visited[i]=false;
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