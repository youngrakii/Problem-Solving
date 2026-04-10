#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,false);
    
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        
        queue<int> q;
        q.push(i);
        visited[i]=true;
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            
            for(int next=0; next<n; next++){
                if(computers[cur][next]==1 && !visited[next]){
                    visited[next]=true;
                    q.push(next);
                }
            }
        }
        
        answer++;
    }
    return answer;
}