#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 웅덩이를 -1로 표시
    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];
        dp[y][x] = -1;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;

            // 웅덩이면 그대로 넘김
            if (dp[i][j] == -1) continue;

            int up = 0;
            int left = 0;

            if (dp[i - 1][j] != -1) up = dp[i - 1][j];
            if (dp[i][j - 1] != -1) left = dp[i][j - 1];

            dp[i][j] = ((long long)up + left) % MOD;
        }
    }

    return dp[n][m];
}