#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    
    for(int i=0; i<T; i++){
        int n;
        cin>>n;
        vector<int> dp(n+1, 0);
        
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        
        for(int j=4; j<=n; j++){
            dp[j]=dp[j-1] + dp[j-2] + dp[j-3];
        }
        cout<< dp[n] << "\n";
    }
    
    return 0;
}