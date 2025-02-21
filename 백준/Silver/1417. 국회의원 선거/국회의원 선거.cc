#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

struct cmp{
    bool operator()(int a, int b){
        return a < b;
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main(){
    cin>>N;
    int v;
    cin>>v;
    
    for(int i=0; i<N-1; i++){
        int a;
        cin>>a;
        pq.push(a);
    }
    
    int res = 0;
    while(!pq.empty() && v<=pq.top()){
        int t=pq.top();
        pq.pop();
        pq.push(t-1);
        res++;
        v++;
    }
    cout<<res;
    
    return 0;
}