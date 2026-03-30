#include <iostream>
using namespace std;

int N;
int board[33][33];
long long dp[33][33][3]; 
// 0: 가로, 1: 세로, 2: 대각선

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    dp[1][2][0] = 1; // 시작 상태

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 1) continue;

            // 가로 이동
            if (j + 1 <= N && board[i][j + 1] == 0) {
                dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
            }

            // 세로 이동
            if (i + 1 <= N && board[i + 1][j] == 0) {
                dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
            }

            // 대각선 이동
            if (i + 1 <= N && j + 1 <= N &&
                board[i][j + 1] == 0 &&
                board[i + 1][j] == 0 &&
                board[i + 1][j + 1] == 0) {
                dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            }
        }
    }

    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << '\n';
    return 0;
}