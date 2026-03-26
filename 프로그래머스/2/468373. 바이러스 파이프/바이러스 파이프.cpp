#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer;
int N,K;
vector<vector<pair<int,int>>> graph;


vector<int> spread(vector<int>& infected, int pipeType){
    vector<int> nextInfected = infected;
    queue<int> q;
    
    for(int i=1; i<=N; i++){
        if(nextInfected[i]){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(auto edge: graph[cur]){
            int next = edge.first;
            int type = edge.second;
            
            if(type!=pipeType) continue;
            if(nextInfected[next]) continue;
            
            nextInfected[next] =1;
            q.push(next);
        }
    }
    
    return nextInfected;
    
}

int countInfected(vector<int>& infected){
    int cnt=0;
    for(int i=1; i<=N; i++){
        if(infected[i]) cnt++;
    }
    
    return cnt;
}

void dfs(int depth, vector<int>& infected, int prevType){
    
    answer=max(answer,countInfected(infected));
    if(depth==K) return;
    
    for(int type=1; type<=3; type++){
        vector<int> nextInfected = spread(infected,type);
        dfs(depth+1,nextInfected,type);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    N=n;
    K=k;
    answer=0;
    graph.assign(N+1, vector<pair<int,int>>());
    
    for(auto edge:edges){
        int a=edge[0];
        int b=edge[1];
        int type=edge[2];
        
        graph[a].push_back({b,type});
        graph[b].push_back({a,type});
    }
    
    vector<int> infected(N+1,0);
    infected[infection]=1;
    
    dfs(0,infected,0);
    
    return answer;
}