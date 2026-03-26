#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

struct State {
    int x1, y1, x2, y2, cnt;
};

int N, M;
vector<string> board;
bool visited[20][20][20][20];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isOut(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= M;
}

int main() {
    cin >> N >> M;
    board.resize(N);

    vector<pair<int, int>> coins;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'o') {
                coins.push_back({i, j});
            }
        }
    }

    int sx1 = coins[0].first;
    int sy1 = coins[0].second;
    int sx2 = coins[1].first;
    int sy2 = coins[1].second;

    queue<State> q;
    q.push({sx1, sy1, sx2, sy2, 0});
    visited[sx1][sy1][sx2][sy2] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.cnt >= 10) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nx1 = cur.x1 + dx[dir];
            int ny1 = cur.y1 + dy[dir];
            int nx2 = cur.x2 + dx[dir];
            int ny2 = cur.y2 + dy[dir];

            bool out1 = isOut(nx1, ny1);
            bool out2 = isOut(nx2, ny2);

            // 둘 다 떨어진 경우
            if (out1 && out2) continue;

            // 하나만 떨어진 경우
            if (out1 || out2) {
                cout << cur.cnt + 1 << '\n';
                return 0;
            }

            // 벽이면 원래 자리 유지
            if (board[nx1][ny1] == '#') {
                nx1 = cur.x1;
                ny1 = cur.y1;
            }
            if (board[nx2][ny2] == '#') {
                nx2 = cur.x2;
                ny2 = cur.y2;
            }

            if (!visited[nx1][ny1][nx2][ny2]) {
                visited[nx1][ny1][nx2][ny2] = true;
                q.push({nx1, ny1, nx2, ny2, cur.cnt + 1});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}