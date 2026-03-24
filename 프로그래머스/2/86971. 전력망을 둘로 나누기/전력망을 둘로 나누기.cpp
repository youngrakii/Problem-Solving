#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){
    visited[node]=true;
    int count=1;
    
    for(int next:graph[node]){
        if(!visited[next]){
            count+=dfs(next,graph,visited);
        }
    }
    
    return count;
    
    
}
int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for(int i=0; i<wires.size(); i++){
        vector<vector<int>> graph(n+1);
        
        for(int j=0; j<wires.size(); j++){
            if(i==j) continue;
            
            int a= wires[j][0];
            int b=wires[j][1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<bool> visited(n+1,false);
        
        int count = dfs(1,graph,visited);
        int other = n-count;
        
        answer = min(answer,abs(count-other));
    }
    return answer;
}