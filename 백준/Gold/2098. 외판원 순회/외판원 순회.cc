#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

const int INF = 987654321;
int n, start[20], end[20], s, e, cost, dp[20][1<<(16)], mp[20][20];
vector <tuple<int,int,int>> v;
vector<vector<int>> v_list;

int go(int start, int visited){
    if(visited == (1<<n)-1){
        return mp[start][0]?mp[start][0]:INF;
    }

    int &ret = dp[start][visited];
    if(ret!=-1) return ret;

    ret=INF;
    for(int i=0; i<n; i++){
        if(visited&(1<<i)) continue;
        if(mp[start][i]==0) continue;
        ret = min(ret,go(i,visited | (1<<i))+mp[start][i]);
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cost;
            mp[i][j]=cost;
        }
    }

    memset(dp,-1,sizeof(dp));
    
    cout<<go(0,1);
}



