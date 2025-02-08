#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
pair<int,int> arr[100001];
priority_queue<int, vector<int>,greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int temp,cur,room=0;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>temp>>arr[i].first>>arr[i].second;
    }
    
    sort(arr,arr+n);
    
    for(int i=0; i<n; i++){
        if(pq.size()){
            if(pq.top()>arr[i].first) room++;
            else pq.pop();
        }
        else room++;
        
        pq.push(arr[i].second);
    }
    cout<<room;
    
    return 0;
}