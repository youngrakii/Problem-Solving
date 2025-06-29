#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> arr(51);
int temp[51]={0};
int parent[51]={0};
int child[51]={0};
int n,a,tick=1;
int ans=0;

int compare(int a, int b){
	return a>b;
}

int dfs(int idx){
	if(!arr[idx].size()){
		return 1;
	}

	int ret=0;
	vector<int> v;
	for(int i=0; i<arr[idx].size(); i++){
		v.push_back(dfs(arr[idx][i]));
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++){
		ret=max(ret,v[i]+i);
	}

	return ret+1;
}


int main() {
	cin>>n>>a;

	for(int i=1; i<n; i++){
		cin>>parent[i];
		arr[parent[i]].push_back(i);
		child[parent[i]]++;
	}

	cout<<dfs(0)-1;
	return 0;
}