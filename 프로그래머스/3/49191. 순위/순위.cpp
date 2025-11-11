#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool A[101][101]={false,};
    
    for(auto r:results){
        A[r[0]][r[1]] = true;
    }
    
    for(int k=1; k<=n;k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(A[i][k]==true && A[k][j] == true){
                    A[i][j]=true;
                }
            }
        }
    }
    
    for(int a=1; a<=n; a++){
        bool flag = true;
        for(int b=1; b<=n; b++){
            if(a==b) continue;
            if(A[a][b]==false && A[b][a]==false){
                flag = false;
                break;
            }
        }
        
        if(flag == true) answer++;
    }
    return answer;
}