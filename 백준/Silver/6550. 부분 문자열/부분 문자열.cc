#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string a,b;
    while(cin>>a>>b){
        int aldx=0;
        bool isTrue = false;
        for(int i=0; i<b.length();i++){
            if(a[aldx]==b[i]){
                aldx++;
            }
            if(aldx==a.length()){
                isTrue=true;
            }
        }
        if(isTrue){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    return 0;
}