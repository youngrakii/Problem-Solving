#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    
    vector<int> vec(n);
    
    for(int i=0;i<n;i++) cin>>vec[i];
    
    int left=0;
    int right=vec.size()-1;
    
    int cnt=0;
    
    while(left<right){
        int dist=right-left-1;
        int power=min(vec[right],vec[left]);
        cnt = max(cnt,dist*power);
        
        if(vec[right]>vec[left]) left++;
        else right--;
    }
    cout<<cnt<<"\n";
    return 0;
    
}