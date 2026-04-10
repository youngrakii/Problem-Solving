#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    
    // 상하좌우 이동
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // 시작점
    q.push({0, 0});
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 맵 범위를 벗어나면 무시, 벽이면 이동 불가
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || maps[nx][ny]==0) continue;
           
            
            // 아직 방문하지 않은 길이면
            if (maps[nx][ny] == 1) {
                maps[nx][ny] = maps[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    // 도착점에 도달 못했다면
    if (maps[n - 1][m - 1] == 1) return -1;
    
    return maps[n - 1][m - 1];
}