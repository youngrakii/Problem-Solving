#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    
    int cnt=1;
    int layer=1;
    int n;
    
    cin>>n;
    
    while(n>cnt){
        cnt+=6*layer;
        layer++;
    }
    cout<<layer;
    return 0;
}