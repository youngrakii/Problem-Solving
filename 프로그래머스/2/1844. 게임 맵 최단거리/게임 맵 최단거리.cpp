#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int BFS(vector<vector<int>> maps){
    queue<pair<int,int>> q;
    int n=maps.size();
    int m=maps[0].size();
    vector<vector<int>> table(n,vector<int>(m,0));
    q.push({0,0});
    table[0][0]=1;
    
    while(q.size()){
        pair<int,int> current=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny = current.first+dy[i];
            int nx = current.second +dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=m || maps[ny][nx] == 0 || table[ny][nx]) continue;
            table[ny][nx] = table[current.first][current.second]+1;
            q.push({ny,nx});
        }
    }
    
    return table[n-1][m-1]>0 ? table[n-1][m-1]:-1;
}

int solution(vector<vector<int>> maps){
    int answer=BFS(maps);
    return answer;
}