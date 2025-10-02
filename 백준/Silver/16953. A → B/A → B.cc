#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a,b;
    cin>>a>>b;
    
    int result = 1;
    while(true){
        if(a==b) break;
        else if(a>b){
            result = -1;
            break;
        }
        
        if(b%2==0) b/=2;
        else if(b%10==1) b=(b-1)/10;
        else{
            result =-1;
            break;
        }
        result++;
    }
    
    cout<<result<<"\n";
    
    return 0;
}