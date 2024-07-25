#include <iostream>
using namespace std;

int n;
int bag;
int main(){
    cin>>n;
    while(n>=0){
        if(n%5==0){
            bag+=n/5;
            cout<<bag<<"\n";
            return 0;
        }
        n-=3;
        bag++;
    }
    cout<<-1<<"\n";
}
