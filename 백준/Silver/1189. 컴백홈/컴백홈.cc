#include <iostream>
#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
int r, c, k;
int answer;
vector<string> vec;
vector<vector<int>> visited;
 
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
 
void dfs(int x, int y, int cnt)
{
    if (cnt > k) return;
    if (cnt == k && x == 0 && y == c - 1)
    {
        answer++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r) continue;
        if (ny < 0 || ny >= c) continue;
        if (visited[nx][ny]) continue;
        if (vec[nx][ny] == 'T') continue;
 
        visited[nx][ny] = 1;
        dfs(nx, ny, cnt + 1);
        visited[nx][ny] = 0;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> r >> c >> k;
 
    visited.resize(r, vector<int>(c, 0));
 
    string temp;
    for (int i = 0; i < r; i++)
    {
        cin >> temp;
        vec.push_back(temp);
    }
 
    visited[r - 1][0] = 1;
    dfs(r - 1, 0, 1);
 
    cout << answer;
 
    return 0;
}
 