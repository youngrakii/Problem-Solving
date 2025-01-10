#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N,M, cnt{0};
int Map[1001][1001];
int start_x, start_y;
bool visited[1001][1001];
queue<pair<int,int>> q;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void BFS(int org_x, int org_y){
   q.push({org_x,org_y});
   visited[org_y][org_x]=true;
   Map[org_y][org_x]=cnt;
   cnt++;
   while(!q.empty()){
      int q_size = q.size();
      for(int i=0; i<q_size; i++){
         int x = q.front().first;
         int y = q.front().second;
         q.pop();

         for(int j=0; j<4; j++){
            int nx = x+dx[j];
            int ny = y+dy[j];
            if(nx<0||nx>=M||ny<0||ny>=N){
               continue;
            }
            if(visited[ny][nx]){
               continue;
            }
            if(!Map[ny][nx]){
               continue;
            }
            Map[ny][nx]=cnt;
            visited[ny][nx]=true;
            q.push({nx,ny});
         }
      }
      cnt++;
   }
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cin>>N>>M;
   for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
         cin>>Map[i][j];
         if(Map[i][j]==2){
            start_x=j;
            start_y=i;
         }
      }
   }
   BFS(start_x,start_y);
   for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
         if(visited[i][j]){
            cout<<Map[i][j]<<' ';
         }
         else{
            if(!Map[i][j]){
               cout<<0<<' ';
            }
            else{
               cout<<-1<<' ';
            }
         }
      }
      cout<<'\n';
   }

   return 0;
}