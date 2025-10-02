#include <iostream>

using namespace std;

int adj[101][101];
int n;

void fw(){
    for(int k=0;k<n;k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj[i][j]==0 && adj[i][k]==1 && adj[k][j]==1){
                    adj[i][j]=1;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adj[i][j];
        }
    }
    
    fw();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}