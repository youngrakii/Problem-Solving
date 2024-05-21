#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s_add(string s1, string s2){
    string ret = "";
    int s1len = s1.length(), s2len = s2.length();
    int is_carry = 0;
    int i;
    for(i = 0; i<s2len; i++){
        char s = s1[i]-'0' + s2[i] + is_carry;
        if(s > '9'){
            is_carry = 1;
            s -= 10;
        } else {
            is_carry = 0;
        }
        ret += s;
    }
    for(int j=i; j<s1len; j++){
        char s = s1[j] + is_carry;
        if(s > '9'){
            is_carry = 1;
            s -= 10;
        } else {
            is_carry = 0;
        }
        ret += s;
    }
    if(is_carry){
        ret += "1";
    }
    return ret;
}
vector <string> v (10001);
int main(){
    int n;
    cin>>n;
    for(int i=0; i<=10000; i++){
        v[i] = "0";
    }
    v[2] = v[1] = "1";
    for(int i=3; i<=10000;i++){
        v[i] = s_add(v[i-1], v[i-2]);
    }
    reverse(v[n].begin(), v[n].end());
    cout<< v[n] <<endl;
    return 0;
}
