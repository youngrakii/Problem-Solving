#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    //반대로 거리를 기준으로 찾는다.
    int answer = 0;
    int st=0;
    int end=distance;
    int mid=0;
    
    sort(rocks.begin(),rocks.end());
    rocks.push_back(distance);
    while(st<=end){
        mid=(st+end)/2;
        int prevRock=0;
        int rockCnt=0;
        for(int i=0; i<rocks.size(); i++){
            if(rocks[i]-prevRock<mid){
                //제거해주어야 하는 돌들
                rockCnt+=1;
            }
            else{
                prevRock=rocks[i];
            }
        }
        if(rockCnt>n){
            //제거할 돌이 많다면 거리가 멀다는 뜻
            end=mid-1;
        }
        else{
            answer=mid;
            st=mid+1;
        }
    }
    return answer;
}