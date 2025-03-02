#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> out; // 각 작업의 완료까지 필요한 일 수
    vector<int> answer; // 배포 개수 리스트
    
    // 각 작업이 완료되는 데 걸리는 일수 계산
    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int days = (remain % speeds[i] == 0) ? (remain / speeds[i]) : (remain / speeds[i] + 1);
        out.push_back(days);
    }
    
    // 배포 그룹 계산
    int max_days = out[0]; // 첫 번째 작업이 기준
    int count = 1;

    for (int i = 1; i < out.size(); i++) {
        if (out[i] <= max_days) {
            // 현재 작업이 이전 작업보다 늦게 끝나지 않으면 같은 날 배포
            count++;
        } else {
            // 새로운 배포 그룹
            answer.push_back(count);
            count = 1;
            max_days = out[i]; // 새로운 기준일 변경
        }
    }

    // 마지막 배포 그룹 추가
    answer.push_back(count);

    return answer;
}
