#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    vector<vector<pair<int, int>>> graph(n);
    
    for (auto& cost : costs) {
        int a = cost[0];
        int b = cost[1];
        int c = cost[2];
        
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 0}); // {비용, 정점}
    
    int answer = 0;
    int cnt = 0;
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (visited[now]) continue;
        
        visited[now] = true;
        answer += cost;
        cnt++;
        
        //if (cnt == n) break;
        
        for (auto& next : graph[now]) {
            int nextNode = next.first;
            int nextCost = next.second;
            
            if (!visited[nextNode]) {
                pq.push({nextCost, nextNode});
            }
        }
    }
    
    return answer;
}