#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<string> v1(n);
    vector<string> result;
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    
    sort(v1.begin(),v1.end());
    
    string str;
    int count=0;
    for(int i=0; i<m; i++){
        cin>>str;
        if(binary_search(v1.begin(),v1.end(),str)){
            count++;
        }
    }
    cout<<count;
    return 0;
}