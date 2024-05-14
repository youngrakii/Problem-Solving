#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
int INF = 1e9 + 7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs
#define X first
#define Y second
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
int board[8][8];
int tmp[8][8];
vector<pair<int, int>> space;
bool vis[64];
int ans; // 안전 영역의 최대 크기
/**
 * 1. 모든 경우에 대해서 벽을 3개 세움
 * 2. 각 경우에 대해서 안전 영역의 크기를 구함.
 * 3. 안전 영역 중 최댓값을 저장
 */
void copyArray(int des[8][8], int src[8][8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            des[i][j] = src[i][j];
        }
    }
}
void spreadVirus() {
    int spread[8][8];
    copyArray(spread, tmp);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread[i][j] == 2) q.push({ i,j });
        }
    }
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (spread[nx][ny] == 0) {
                spread[nx][ny] = 2;
                q.push({ nx,ny });
            }
        }
    }

    int cnt = 0; // 모든 경우의 안전 영역의 크기 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spread[i][j] == 0) cnt++;
        }
    }
    ans = max(ans, cnt);
}
// 입력 받을 때 모든 빈칸을 1차원 배열로 받은 뒤, 해당 배열을 조합하는 방법
void wall(int cur, int idx) {
    if (cur == 3) {
        copyArray(tmp, board);
        int cnt = 0;
        for (int i = 0; i < (int)space.size(); i++) {
            if (cnt == 3) break;
            if (vis[i]) {
                int x = space[i].first;
                int y = space[i].second;
                tmp[x][y] = 1;
                cnt++;
            }
        }
        spreadVirus();
        return;
    }
    for (int i = idx; i < (int)space.size(); i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        wall(cur + 1, i);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0)
                space.push_back({ i,j });
        }
    }
    wall(0, 0);
    cout << ans;
    return 0;
}