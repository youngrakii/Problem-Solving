#include <iostream>
#include <vector>
using namespace std;


vector<bool> colUsed;
vector<bool> diag1Used;
vector<bool> diag2Used;
int answer=0;
int N;

void dfs(int row){
	if(row==N){
		answer++;
		return;
	}

	for(int col=0; col<N; col++){
		if(colUsed[col]||diag1Used[row-col+N-1]||diag2Used[row+col]) continue;
		
		colUsed[col]=true;
		diag1Used[row-col+N-1]=true;
		diag2Used[row+col]=true;
		dfs(row+1);
		diag2Used[row+col]=false;
		diag1Used[row-col+N-1]=false;
		colUsed[col]=false;

	}

	
	
}

int main() {
	// 코드 작성
	cin>>N;
	colUsed.assign(N,false);
	diag1Used.assign(2*N-1,false);
	diag2Used.assign(2*N-1,false);

	dfs(0);

	cout<<answer<<'\n';


	return 0;
}