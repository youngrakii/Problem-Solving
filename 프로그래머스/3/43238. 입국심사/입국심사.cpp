#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    //가장 큰 값을 뽑기 위해 정렬
    //해당 함수는 max_element()를 사용해도 됨.
    sort(times.begin(), times.end());
    
    long long min=1;
    
    //주의. 데이터 타입
    long long max=n*(long long)times.back();
    
    //이분탐색
    //최대값과 최솟값이 바뀌는 구간이 가장 최소 시간이다.
    while (min<=max){
        long long avg=(max+min)/2;
        long long tmp=0;
        
        //현재 시간 기준으로 심사위원들이
        //몇 명을 처리하는지 확인하느 부분
        for(int i=0; i<times.size(); i++){
            tmp+=(avg/(long long) times[i]);
        }
        
        //현재 값보다 많은 사람을 처리할 수 있을 경우
        if(tmp>=n){
            max=avg-1;
            answer=avg;
        }
        
        //현재 값보다 적은 사람을 처리할 수 있는 경우
        else min=avg+1;
    }
    
    return answer;
}