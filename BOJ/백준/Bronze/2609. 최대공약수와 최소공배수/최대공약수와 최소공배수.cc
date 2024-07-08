#include <iostream>
using namespace std;

int gcd(int a, int b){
    int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<"\n";
    cout<<lcm(a,b)<<"\n";
}