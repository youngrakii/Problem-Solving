#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    
    dp[1]=0;
    
    for(int i=2; i<=n; i++){
        //1. 1을 뺀다.
        dp[i]=dp[i-1]+1;
        
        //2. 3으로 나누어지면
        if(!(i%3)) dp[i] = min(dp[i],dp[i/3]+1);
        
        //3. 2로 나누어지면
        if(!(i%2)) dp[i] = min(dp[i], dp[i/2]+1);
    }
    
    cout<<dp[n]<<"\n";
    
    return 0;
}