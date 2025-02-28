#include <iostream>

using namespace std;

int n, sum, ans;
int coin[101];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> sum;
    
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= sum; j++) {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }
    
    cout << dp[sum];
}