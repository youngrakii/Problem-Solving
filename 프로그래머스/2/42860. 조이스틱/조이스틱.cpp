#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();

    // 1. 위아래 이동 횟수 계산
    for (char c : name) {
        answer += min(c - 'A', 'Z' - c + 1);
    }

    // 2. 좌우 이동 횟수 계산
    int move = n - 1;  // 기본: 오른쪽으로만 끝까지 이동

    for (int i = 0; i < n; i++) {
        int next = i + 1;

        // i 다음부터 연속된 A 구간 찾기
        while (name[next] == 'A') {
            next++;
        }

        // 오른쪽으로 갔다가 돌아오기
        int case1 = i * 2 + (n - next);

        // 왼쪽(끝쪽) 먼저 갔다가 오기
        int case2 = i + (n - next) * 2;

        move = min(move, min(case1, case2));
    }

    answer += move;
    return answer;
}