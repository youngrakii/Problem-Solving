#include <iostream>

using namespace std;

int n, m, ans;

int paper[555][555];
int visited[555][555];

int dy[4] = {1, 0, -1, 0}; // 상하좌우를 표시한다.
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt, int val) {
    if (cnt == 4) ans = ans < val ? val : ans;
    else {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i]; int nx = x + dx[i]; // y, x의 상하좌우에 있는 값
            
            if (ny < 1 or ny > n or nx < 1 or nx > m) continue; // 범위제한
            
            if (visited[ny][nx]) continue; // 이미 방문한 곳이면 방문하지 않는다
            
            visited[ny][nx]++; // 방문한 곳을 표시
            
            dfs(ny, nx, cnt + 1, val + paper[ny][nx]); // 더 깊숙이가거나, 테트로미노임을 확인한다
            
            visited[ny][nx]--; // 표시를 삭제
            
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> paper[i][j];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            visited[i][j]++; // 방문한 곳을 표시
            dfs(i, j, 1, paper[i][j]); // 테트로미노
            visited[i][j]--; // 표시를 삭제
        }
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            int t = paper[i][j]; // 보라색 테트로미노의 가운데를 표시한다
            int mini = 1001;
            for(int k=0; k<4; k++){
                mini=mini<paper[i+dy[k]][j+dx[k]] ? mini : paper[i+dy[k]][j+dx[k]]; //가운데 점의 상하좌우에 있는 값 중에 최소의 값을 나타낸다.
                t += paper[i +dy[k]][j+dx[k]]; // 상하좌우에 있는 값을 모두 더한다. 그러면 십자가 모양처럼 되니 테트로미노가 아니다.
            }
            ans = ans < t - mini ? t - mini : ans; 
        }
    }
    cout << ans;
    return 0;
}