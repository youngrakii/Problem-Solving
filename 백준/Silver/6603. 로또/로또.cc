#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(1){
        int k;
        cin>>k;
        if(k==0) break;
        
        vector<int> v(k);
        for(int i=0; i<k;i++){
            cin>>v[i];
        }
        
        vector<bool> lotto(k,true);
        
        for(int i=0;i<6;i++){
            lotto[i] =false;
        }
        
        do{
            for(int i=0; i<v.size();i++){
                if(!lotto[i]) cout<<v[i]<<" ";
            }
            cout<<"\n";
        }while(next_permutation(lotto.begin(), lotto.end()));
        
        cout<<"\n";
    }
    return 0;
}