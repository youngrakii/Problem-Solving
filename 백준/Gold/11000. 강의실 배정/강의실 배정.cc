#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin>>N;
    
    vector<pair<int,int>> v;
    for(int i=0; i<N; i++){
        int start, end;
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end());
    
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(v[0].second);
    for(int i=1; i<v.size(); i++){
        if(v[i].first>=pq.top()){
            pq.pop();
            pq.push(v[i].second);
        }
        else{
            pq.push(v[i].second);
        }
    }
    
    cout<<pq.size()<<"\n";
    return 0;
}