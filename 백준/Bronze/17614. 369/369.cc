#include <iostream>
using namespace std;

bool Contains369(int n){
    while(n>0){
        if(n%10==3 || n%10 ==6 || n%10==9){
            return true;
        }
        n/=10;
    }
    return false;
}
bool Is369numbers(int n){
    return Contains369(n) || (n%3==0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin>>a;
    int cnt=0;
    for(int i=1; i<=a; i++){
        if(Is369numbers(i)){cnt++;}
    }
    cout<<cnt;
    return 0;
}