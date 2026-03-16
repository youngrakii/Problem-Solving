#include <string>
#include <vector>
#include <numeric>  // gcd
using namespace std;

long long getGcd(long long a, long long b){
    return b==0 ? a:getGcd(b,a%b);
}
long long getLcm(long long a, long long b) {
    return a *b / getGcd(a, b);
}

int solution(vector<vector<int>> signals) {
    long long totalCycle = 1;

    // 모든 신호등 주기의 최소공배수 계산
    for (int i = 0; i < signals.size(); i++) {
        int G = signals[i][0];
        int Y = signals[i][1];
        int R = signals[i][2];
        int cycle = G + Y + R;
        totalCycle = getLcm(totalCycle, cycle);
    }

    // 1초부터 최소공배수 시점까지만 확인
    for (long long t = 1; t <= totalCycle; t++) {
        bool allYellow = true;

        for (int i = 0; i < signals.size(); i++) {
            int G = signals[i][0];
            int Y = signals[i][1];
            int R = signals[i][2];
            int cycle = G + Y + R;

            // 현재 신호등이 한 주기 안에서 몇 번째 초인지
            int pos = (t - 1) % cycle + 1;

            // 노란불 구간: G+1 ~ G+Y
            if (!(G < pos && pos <= G + Y)) {
                allYellow = false;
                break;
            }
        }

        if (allYellow) {
            return t;
        }
    }

    return -1;
}