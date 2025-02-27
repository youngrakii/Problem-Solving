#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순
    
    while(n--){
        int x;
        cin>>x;
        if(x==0){
            if(pq.size()==0){
                cout<<"0\n";
            }
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
            
        }
        else{
            pq.push(x);
        }
        
    }
    return 0;
}