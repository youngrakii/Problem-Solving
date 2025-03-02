#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    int a;
    int b;
    cin>>n;
    vector<pair<int,int>> v;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        q.push(v[i].second);
        if(v[i].first<q.size()) q.pop();
    }
    
    int sum=0;
    while(!q.empty()){
        sum+=q.top();
        q.pop();
    }
    
    cout<<sum<<"\n";
    
}