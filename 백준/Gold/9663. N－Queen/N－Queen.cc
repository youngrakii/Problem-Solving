#include <iostream>
#include <cmath>

using namespace std;

int col[16];
int n;
int ans=0;

void queen(int x){
    if(n==x){
        ans++;
    }else{
        for(int i=0; i<n; i++){
            col[x]=i; //퀸의 위치를 정함
            bool can = true;
            for(int j=0; j<x; j++){
                if(col[x]==col[j]||abs(col[x]-col[j])==x-j){
                    can = false;
                    break;
                }
            }
            if(can){ //충돌하지 않는다면 다음 행으로 넘어감.
                queen(x+1);
            }
        }
    }
} //백트래킹


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    queen(0);
    cout<<ans<<"\n";
    return 0;
}