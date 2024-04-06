#include <iostream>
#include <vector>

using namespace std;

int N,M;
int result = 0;
vector<vector<int>> work(2,vector<int>(3,0));

void dfs(int day, double sum, int prev){
    if (day==N){
        if (sum >= M){
        result++;
        }
        return;
    }
    
    for(int a=0; a<2;a++){
        for(int b=0;b<3;b++){
            double next_sum=sum;
            if(b==prev){
                next_sum+=work[a][b]/2.0;
            }
            else{
                next_sum+=work[a][b];
            }
            dfs(day+1,next_sum,b);
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<2; i++){
        for(int k=0; k<3; k++){
            cin>>work[i][k];
        }
    }
    
    dfs(0,0.0,-1);
    cout<<result<<endl;
    return 0;
}