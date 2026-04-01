#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int maxAlp = alp;
    int maxCop = cop;
    
    // 도달해야 할 최종 목표 능력치
    for (const auto& p : problems) {
        maxAlp = max(maxAlp, p[0]);
        maxCop = max(maxCop, p[1]);
    }
    
    
    const int INF = 1e9;
    vector<vector<int>> dp(maxAlp + 1, vector<int>(maxCop + 1, INF));
    dp[alp][cop] = 0;
    
    for (int a = alp; a <= maxAlp; a++) {
        for (int c = cop; c <= maxCop; c++) {
            if (dp[a][c] == INF) continue;
            
            // 1) 알고력 공부
            if (a + 1 <= maxAlp) {
                dp[a + 1][c] = min(dp[a + 1][c], dp[a][c] + 1);
            }
            
            // 2) 코딩력 공부
            if (c + 1 <= maxCop) {
                dp[a][c + 1] = min(dp[a][c + 1], dp[a][c] + 1);
            }
            
            // 3) 문제 풀기
            for (const auto& p : problems) {
                int alpReq = p[0];
                int copReq = p[1];
                int alpRwd = p[2];
                int copRwd = p[3];
                int cost   = p[4];
                
                if (a >= alpReq && c >= copReq) {
                    int nextA = min(maxAlp, a + alpRwd);
                    int nextC = min(maxCop, c + copRwd);
                    dp[nextA][nextC] = min(dp[nextA][nextC], dp[a][c] + cost);
                }
            }
        }
    }
    
    return dp[maxAlp][maxCop];
}