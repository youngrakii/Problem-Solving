#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(),cmp); //진출지점 기준 정렬
   
    int camera = -30001;
    
    for(int i=0; i<routes.size(); i++){
        int start = routes[i][0];
        int end = routes[i][1];
        
        //현재 카메라가 이 차량 구간을 커버하지 못하면 새로 설치
        if(camera<start){
            answer++;
            camera = end;
        }
    }
    return answer;
}