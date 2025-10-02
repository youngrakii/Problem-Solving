#include <iostream>
#include <set>

using namespace std;

struct cmp{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int number;
    cin>>number;
    
    multiset<pair<int,int>,cmp> location;
    for(int i=0; i<number; i++){
        int num1,num2;
        cin>>num1>>num2;
        location.insert(pair<int,int>(num1,num2));
    }
    
    for(auto it = location.begin(); it!=location.end(); it++){
        cout<<it->first<<" "<<it->second<<"\n";
    }
    
    return 0;
}