#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int widthHeight, numOfOpen;
bool visit[50][50];
vector<pair<int, int>> chickenOpenPoint;
vector<pair<int, int>> homePoint;
vector<pair<int, int>> chickenPoint;
int cityDistance;
int result = 1e10;

void selectByBackTracking(int idx, int lastCheck) {
    if (idx >= numOfOpen) {
        cityDistance = 0;
        for (pair<int, int> home : homePoint) {
            int distance = 1e10;
            for (pair<int, int> chicken : chickenOpenPoint) {
                distance = min(distance, abs(home.first - chicken.first) + abs(home.second - chicken.second));
            }
            cityDistance += distance;
        }
        result = min(result, cityDistance);
        return;
    }
    else {
        for (int i = lastCheck + 1; i < chickenPoint.size(); i++) {
            pair<int, int> chicken = chickenPoint[i];
            chickenOpenPoint.push_back({ chicken.first, chicken.second });
            visit[chicken.first][chicken.second] = true;
            selectByBackTracking(idx + 1, i);
            visit[chicken.first][chicken.second] = false;
            chickenOpenPoint.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> widthHeight >> numOfOpen;

    int input;
    for (int i = 0; i < widthHeight; i++) {
        for (int j = 0; j < widthHeight; j++) {
            cin >> input;
            if (input == 1) { homePoint.push_back({ i, j}); }
            if (input == 2) { chickenPoint.push_back({ i, j}); }
        }
    }

    for (int i = 0; i < chickenPoint.size(); i++) {
        pair<int, int> chicken = chickenPoint[i];
        chickenOpenPoint.push_back({ chicken.first, chicken.second });
        visit[chicken.first][chicken.second] = true;
        selectByBackTracking(1, i);
        visit[chicken.first][chicken.second] = false;
        chickenOpenPoint.pop_back();
    }
    cout << result;

    return 0;
}
