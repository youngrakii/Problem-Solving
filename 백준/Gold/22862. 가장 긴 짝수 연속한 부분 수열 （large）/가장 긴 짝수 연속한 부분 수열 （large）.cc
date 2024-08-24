#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> vec;
int even;
int odd;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>k;
    
    vec.resize(n);
    for(int& i : vec) cin>>i;
    
    int s=0;
    int e=0;
    int ans=0;
    
    while(e<n){
        if(odd<=k){
            if(vec[e]%2){
                odd++;
            }
            else{
                even++;
                ans=max(ans,even);
            }
            e++;
        }
        else if(odd>k){
            if(vec[s]%2){
                odd--;
            }
            else{
                even--;
            }
            s++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}