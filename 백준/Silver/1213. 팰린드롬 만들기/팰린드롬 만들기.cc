#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int alpha[26];
string odd;
string even;
int main(){
    string s;
    cin>>s;
    for(char i:s){
        alpha[i]++;
    }
    for(char i='A'; i<='Z'; i++){
        if(alpha[i]%2)
        {
            odd+=i;
        }
        for(int j=0;j<alpha[i]/2;j++){
            even+=i;
        }
    }
    if(odd.size()>1){
        cout<<"I'm Sorry Hansoo";
    }
    else{
        cout<<even;
        cout<<odd;
        reverse(even.begin(),even.end());
        cout<<even;
    }
}