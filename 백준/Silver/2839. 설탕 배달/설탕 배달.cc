#include <iostream>
using namespace std;

int main(){
    int n;
    int dp[5001];
    cin>>n;
    dp[3]=1;
    dp[5]=1;
    for(int i=6;i<=n;i++){
        if(dp[i-3]){
            dp[i]=dp[i-3]+1;
        }
        if(dp[i-5]){
            dp[i]=dp[i-5]+1;
        }
    }
    if(dp[n]){
        cout<<dp[n];
    }
    else{
        cout<<-1;
    }
}
