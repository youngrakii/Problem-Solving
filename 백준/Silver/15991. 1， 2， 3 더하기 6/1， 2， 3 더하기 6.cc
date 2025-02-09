#include <iostream>
#define M 1000000009

using namespace std;

int T, N, dp[100001]={};

int main(){
    dp[1]=1;
    dp[2]=2;
    dp[3]=2;
    dp[4]=3;
    dp[5]=3;
    dp[6]=6;
    
    for(int i=7; i<=100000; i++){
        dp[i]=((dp[i-2]+dp[i-4])%M + dp[i-6])%M;
    }
    
    cin>>T;
    while(T--){
        cin>>N;
        cout<<dp[N]<<"\n";
    }
}