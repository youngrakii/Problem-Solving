#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int res;
bool visited[9];

int dfs(vector<vector<int>> dungeons, int k, int cnt){
    res = max(res, cnt); // 최대 던전 수
    
    for(int i=0; i<dungeons.size(); i++){
        // 방문 || 최소 필요도 > 현재 피로도
        if(visited[i] || dungeons[i][0] > k) continue;
        
        visited[i] = 1;
        dfs(dungeons, k - dungeons[i][1], cnt+1); // 현재 피로도 - 소모 피로도
        visited[i] = 0;
    }
    return res;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    answer = dfs(dungeons, k, 0);
    return answer;
}