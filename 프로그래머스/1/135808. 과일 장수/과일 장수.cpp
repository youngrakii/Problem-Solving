#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    // 1. 점수 내림차순 정렬
    sort(score.begin(), score.end(), greater<int>());

    // 2. m개씩 묶어서 상자를 만들 수 있는 만큼만 사용
    //    i는 각 박스에서 '최저 점수'가 위치하는 인덱스 (m-1, 2m-1, ...)
    for (int i = m - 1; i < (int)score.size(); i += m) {
        int p = score[i];     // 이 상자의 최저 점수
        answer += p * m;      // 상자 가격 = p * m
    }

    return answer;
}
