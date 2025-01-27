#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int alphabet[26]={0};
    string s;
    
    cin>>s;
    int len=s.length();
    
    for(int i=0; i<len; i++){
        if(s[i]<91) alphabet[s[i]-65]++;
        else alphabet[s[i]-97]++;
    }
    
    int max = 0;
    int maxidx=0;
    
    for(int i=0; i<26; i++){
        if(max < alphabet[i]){
            max = alphabet[i];
            maxidx=i;
        }
    }
    
    int cnt=0;
    for(int i=0;i<26;i++){
        if(max==alphabet[i]) cnt++;
        if(cnt>1){
            cout<<'?';
            break;
        }
    }
    if(cnt==1) cout<< (char) (maxidx+65);
    
    return 0;
}