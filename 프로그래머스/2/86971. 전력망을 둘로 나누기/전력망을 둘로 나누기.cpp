#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int gap(vector<vector<int>> v){
    vector<int> visited(v.size());
    queue<int> q;
    
    q.push(1);
    int cnt=0;
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(visited[cur]==1) continue;
        visited[cur]=1;
        cnt++; //이어진 송전탑의 개수
        for(int i=0; i<v[cur].size(); i++){
            q.push(v[cur][i]);
        }
    }
    int cnt2=v.size()-1-cnt;
    return abs(cnt2-cnt);
}

int solution(int n, vector<vector<int>> wires){
    int answer=100;
   
    for(int i=0; i<wires.size(); i++){
        vector<vector<int>> v(n+1);
        for(int j=0; j<wires.size(); j++){
            if(i==j) continue;
            int stt=wires[j][0];
            int end=wires[j][1];
            v[stt].push_back(end);
            v[end].push_back(stt);
        }
        answer=min(answer,gap(v));
        //v.clear();
    }
    
    return answer;
}