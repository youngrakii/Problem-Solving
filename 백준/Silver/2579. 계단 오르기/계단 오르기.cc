#include <iostream>
#define MAX 310

using namespace std;

int N;
int Stair[MAX];
int DP[MAX]; // 각 계단에 서 있다고 가정했을 때, 얻을 수 있는 최댓값을 저장.

int Max(int A, int B) {
    if (A>B) return A;
    else return B;
}

void Input(){
    cin>>N;
    for(int i=1; i<=N; i++){
        cin >> Stair[i];
    }
}

void Solution(){
    DP[1] = Stair[1];
    DP[2] = Stair[1] + Stair[2];
    for(int i=3; i<=N; i++){
        DP[i] = Max(DP[i-3]+Stair[i]+Stair[i-1],DP[i-2]+Stair[i]);
    } //DP[a]=b의 의미: "a번째 계단을 반드시 밟았을 때, 얻을 수 있는 점수의 최대값은 b점 입니다."
    cout<<DP[N]<<"\n";
}

void Solve(){
    Input();
    Solution();
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    
    Solve();
    return 0;
}