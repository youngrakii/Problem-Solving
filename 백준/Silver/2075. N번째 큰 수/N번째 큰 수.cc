#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solution(int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    int temp;
    for(int i=0; i<n*n; i++){
        cin>>temp;
        pq.push(temp);
        if(pq.size()>n) pq.pop();
    }
    cout<<pq.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    solution(n);
    
   return 0;
}