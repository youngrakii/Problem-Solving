#include <string>
#include <vector>
#include <queue>
using namespace std;

int bfs(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    int cnt = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
            cnt++;
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> winGraph(n + 1);
    vector<vector<int>> loseGraph(n + 1);
    
    for (auto &r : results) {
        int a = r[0];
        int b = r[1];
        
        winGraph[a].push_back(b);   // a가 b를 이김
        loseGraph[b].push_back(a);  // b를 이긴 사람은 a
    }
    
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        int winCnt = bfs(i, winGraph, n);
        int loseCnt = bfs(i, loseGraph, n);
        
        if (winCnt + loseCnt == n - 1) {
            answer++;
        }
    }
    
    return answer;
}