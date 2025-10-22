#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    cin>>N>>M;
    
    vector<vector<pair<int,int>>> g(N+1);
    for(int i=0; i<M; i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    
    int s,t;
    cin>>s>>t;
    
    const int INF = INT_MAX;
    vector<int> dist(N+1,INF);
    dist[s]=0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    
    while(!pq.empty()){
        auto[d,u] = pq.top();
        pq.pop();
        
        if(d>dist[u]) continue;
        for(auto[v,w]:g[u]){
            int nd = d+w;
            if(nd<dist[v]){
                dist[v] = nd;
                pq.push({nd,v});
            }
        }
    }
    
    cout<<dist[t]<<"\n";
    return 0;
}