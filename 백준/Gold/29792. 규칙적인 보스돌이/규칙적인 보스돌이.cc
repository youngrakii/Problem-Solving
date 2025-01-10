#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, K; //M은 캐릭
    cin >> N >> M >> K;
    
    vector<long long> ca(N);
    
    for (int i = 0; i < N; i++) {
        cin >> ca[i];
    }
    
    vector<pair<long long, long long>> boss(K);
    
    for (int i = 0; i < K; i++) {
        cin >> boss[i].first >> boss[i].second;
    }
    
    vector<long long> V(901,0);
    
    vector<long long> maxV(N);
    
    for (int j = 0; j < N; j++)
    {
        V= vector<long long>(901,0);
        for (int k=0; k<K; k++)
        {
            if (ca[j]==0)
            {
                continue;
            }
            long long sTime = (boss[k].first / ca[j])+ (boss[k].first%ca[j]>0?1:0);
            
            for (int i=900; i>=0; i--)
            {
                
                if (i - sTime>=0)
                {
                    V[i] = max({V[i - sTime] + boss[k].second, V[i]});
                }
                
                else {
                    break;
                }
                
            }
            
        }
        
        maxV[j] = V[900];
        
    }
    
    sort(maxV.begin(), maxV.end(), [](long long a, long long b) {
        return a > b; });
    
    int ans = 0;
    
    for (int i = 0; i < min(N,M); i++) {
        ans += maxV[i];
    }
    
    cout << ans << "\n";
    
    return 0;
}