#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(),times.end());
    long long left =1;
    long long right = (long long)times.back()*n;
    
    while(left<=right){
        long long mid = (left+right)/2;
        long long sum=0;
        
        for(long long time:times){
            sum+=mid/time;
            //if(sum>=n) break;
        }
        
        if(sum>=n){
            answer = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return answer;
}