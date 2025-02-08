#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int a;
    vector<int> v(3);
    for(int i=0; i<v.size(); i++){
        cin>>a;
        v[i] = a;
    }
    sort(v.begin(),v.end());
    cout<<v[0]<<" "<<v[1]<<" "<<v[2];
    
    return 0;
}