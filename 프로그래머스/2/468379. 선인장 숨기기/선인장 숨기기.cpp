#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    const int INF = (int)drops.size() + 1;

    // 각 칸에 비가 처음 떨어지는 시각 기록
    // 비가 한 번도 오지 않는 칸은 INF
    vector<vector<int>> rainTime(m, vector<int>(n, INF));
    for (int i = 0; i < (int)drops.size(); i++) {
        int r = drops[i][0];
        int c = drops[i][1];
        rainTime[r][c] = i + 1;
    }

    // 1단계: 각 행마다 길이 w 구간의 최소값 구하기
    int newColCount = n - w + 1;
    vector<vector<int>> rowMin(m, vector<int>(newColCount));

    for (int r = 0; r < m; r++) {
        deque<int> dq; // 열 인덱스 저장

        for (int c = 0; c < n; c++) {
            while (!dq.empty() && rainTime[r][dq.back()] >= rainTime[r][c]) {
                dq.pop_back();
            }
            dq.push_back(c);

            // 윈도우 밖 인덱스 제거
            while (!dq.empty() && dq.front() <= c - w) {
                dq.pop_front();
            }

            if (c >= w - 1) {
                rowMin[r][c - w + 1] = rainTime[r][dq.front()];
            }
        }
    }

    // 2단계: rowMin의 각 열마다 길이 h 구간의 최소값 구하기
    // 각 h x w 부분 격자의 최소값 = 그 구역이 처음 비를 맞는 시각
    int bestTime = -1;
    int bestRow = 0;
    int bestCol = 0;

    for (int c = 0; c < newColCount; c++) {
        deque<int> dq; // 행 인덱스 저장

        for (int r = 0; r < m; r++) {
            while (!dq.empty() && rowMin[dq.back()][c] >= rowMin[r][c]) {
                dq.pop_back();
            }
            dq.push_back(r);

            // 윈도우 밖 인덱스 제거
            while (!dq.empty() && dq.front() <= r - h) {
                dq.pop_front();
            }

            if (r >= h - 1) {
                int topRow = r - h + 1;
                int leftCol = c;
                int currentTime = rowMin[dq.front()][c];

                if (currentTime > bestTime ||
                    (currentTime == bestTime && topRow < bestRow) ||
                    (currentTime == bestTime && topRow == bestRow && leftCol < bestCol)) {
                    bestTime = currentTime;
                    bestRow = topRow;
                    bestCol = leftCol;
                }
            }
        }
    }

    return {bestRow, bestCol};
}