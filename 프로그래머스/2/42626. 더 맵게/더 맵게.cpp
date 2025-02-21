#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    //우선순위큐 오름차순
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    //음식이 최소 2개 이상이고 제일 안 매운 음식이 k보다 작을 때까지만 반복
    while(pq.size()>1 && pq.top()<K){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        //두 개의 음식을 섞어서 우선순위 큐에 추가
        pq.push(first+(second*2));
        
        //조합 횟수 증가
        answer++;
    }
    
    //모든 조합이 끝났을 때 우선순위 큐의 제일 맵지 않은 음식이 K보다 작다면 -1을 리턴
    if(pq.top()<K) return -1;
    return answer;
}