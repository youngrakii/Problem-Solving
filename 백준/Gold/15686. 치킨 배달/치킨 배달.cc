#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;

int N, M;
int city[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<bool> selected;

int result = 1e9;

// 치킨 거리 계산
int calculateDistance() {
    int totalDistance = 0;
    for (const auto& h : house) {
        int minDistance = 1e9;
        for (int i = 0; i < chicken.size(); ++i) {
            if (selected[i]) {
                int dist = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
                minDistance = min(minDistance, dist);
            }
        }
        totalDistance += minDistance;
    }
    return totalDistance;
}

// 치킨집 선택 (조합)
void selectChicken(int idx, int cnt) {
    if (cnt == M) {
        result = min(result, calculateDistance());
        return;
    }
    if (idx == chicken.size()) return;

    // 해당 치킨집 선택
    selected[idx] = true;
    selectChicken(idx + 1, cnt + 1);

    // 해당 치킨집 선택하지 않음
    selected[idx] = false;
    selectChicken(idx + 1, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> city[i][j];
            if (city[i][j] == 1) house.emplace_back(i, j);
            else if (city[i][j] == 2) chicken.emplace_back(i, j);
        }
    }

    selected.resize(chicken.size(), false);
    selectChicken(0, 0);

    cout << result << "\n";

    return 0;
}
