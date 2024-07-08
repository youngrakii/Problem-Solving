#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int map[51][51];
bool visit[51][51];
queue<pair<int,int>> q;
int t,m,n,k,a,b;
int cnt;
void make_empty(){
    memset(map,0,sizeof(map));
    memset(visit,false,sizeof(visit));
    cnt=0;
}

void bfs(int a1,int b1){
    q.push(make_pair(a1,b1));
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int n_x=x+dx[i];
            int n_y=y+dy[i];
            if(n_x<m && n_x>=0 && n_y<n && n_y>=0){
                if(map[n_x][n_y]==1 && !visit[n_x][n_y]){
                    q.push(make_pair(n_x,n_y));
                    visit[n_x][n_y]=true;
                }
            }
        }
    }
}
int main(){
    vector<int> res;
    cin>>t;
    for(int T=0;T<t; T++){
        make_empty();
        cin>>m>>n>>k;
        queue<pair<int,int>> q;
        for(int i=0; i<k;i++){
            cin>>a>>b;
            q.push(make_pair(a,b));
            map[a][b]=1;
        }
        while(!q.empty()){
            int temp1=q.front().first;
            int temp2=q.front().second;
            q.pop();
            if(!visit[temp1][temp2]){
                cnt++;
                bfs(temp1,temp2);
            }
        }
        res.push_back(cnt);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}