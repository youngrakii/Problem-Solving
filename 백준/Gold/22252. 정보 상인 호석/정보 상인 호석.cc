#include <iostream>
#include <queue>
#include <map>

using namespace std;

long long answer = 0;
int n;
int order;
int jewel;
string name;

map<string, priority_queue<int>> m;

void solve(int type){
    if(type==1){
        cin>>name>>jewel;
        
        int number;
        for(int i=0; i<jewel; i++){
            cin>>number;
            m[name].push(number);
        }
    }
    else if(type==2){
        cin>>name>>jewel;
        
        while(jewel--){
            if(m[name].empty()) break;
            answer+=m[name].top();
            m[name].pop();
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>jewel;
        solve(jewel);
    }
    
    cout<<answer<<"\n";
    
    return 0;
}