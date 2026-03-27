#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);
    
    for(auto e:edge){
        int a = e[0];
        int b=e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    q.push(1);
    dist[1]=0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next:graph[cur]){
            if(dist[next]!=-1) continue;
            dist[next] = dist[cur]+1;
            q.push(next);
        }
    }
    
    int maxDist =0;
    for(int i=1; i<=n; i++){
        if(dist[i]>maxDist) maxDist = dist[i];
    }
    
    int answer=0;
    for(int i=1; i<=n; i++){
        if(dist[i]==maxDist) answer++;
    }
    
    return answer;
}