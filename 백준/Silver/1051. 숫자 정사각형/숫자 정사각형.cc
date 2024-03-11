#include <iostream>
#include <algorithm>
using namespace std;

int map[51][51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n,m,answer=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string num;
        cin>>num;
        for(int j=0;j<num.size();j++){
            map[i][j]=num[j]-'0';
        }
    }
    for(int k=2; k<=min(n,m);k++){
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                if(map[i][j]==map[i+k-1][j]&&map[i][j]==map[i][j+k-1]&&map[i][j]==map[i+k-1][j+k-1]){
                    answer=max(answer,k*k);
                }
            }
        }
    }
                   cout<<answer;
                  
}