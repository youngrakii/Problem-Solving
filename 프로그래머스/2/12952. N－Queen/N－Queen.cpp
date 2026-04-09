#include <string>
#include <vector>

using namespace std;
int answer;
vector<bool> colUsed;
vector<bool> diag1Used;
vector<bool> diag2Used;

void dfs(int row,int n){
    //모든 행에 퀸을 다 놓은 경우
    if(row==n){
        answer++;
        return;
    }
    
    //현재 행의 각 열에 대해 퀸을 놓아보기
    for(int col=0; col<n; col++){
        //같은 열, 같은 대각선에 이미 퀸이 있으면 불가능
        if(colUsed[col]|| diag1Used[row-col+n-1] || diag2Used[row+col]) continue;
        
        //퀸 놓기
        colUsed[col]=true;
        diag1Used[row-col+n-1]=true;
        diag2Used[row+col]=true;
        
        dfs(row+1,n);
        
        //원상복구
        colUsed[col]=false;
        diag1Used[row-col+n-1]=false;
        diag2Used[row+col]=false;
        
    }
}

int solution(int n) {
    answer=0;
    
    colUsed.assign(n,false);
    diag1Used.assign(2*n-1,false);
    diag2Used.assign(2*n-1,false);
    
    dfs(0,n);
    
    
    return answer;
}