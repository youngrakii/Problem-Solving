#include <iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    
    int ans=0;
    while(x>0){
        if(x%2==1){
            ans++;
        }
        x/=2;
    }
    cout<<ans;
    return 0;
}