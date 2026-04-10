#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    
    //집이 1개인 경우
    if(n==1) return money[0];
    
    //dp1: 첫 집을 포함하는 경우 -> 마지막 집은 제외
    vector<int> dp1(n,0);
    
    //dp2: 첫 집을 포함하지 않는 경우 -> 마지막 집까지 가능
    vector<int> dp2(n,0);
    
    //첫 집 포함
    dp1[0]=money[0];
    dp1[1]=money[0];
    for(int i=2; i<n-1; i++){
        dp1[i]=max(dp1[i-1],dp1[i-2]+money[i]);
    }
    
    
    //첫 집 제외
    dp2[0]=0;
    dp2[1]=money[1];
    for(int i=2; i<n; i++){
        dp2[i]=max(dp2[i-1],dp2[i-2]+money[i]);
    }
    
    return max(dp1[n-2], dp2[n-1]);
}