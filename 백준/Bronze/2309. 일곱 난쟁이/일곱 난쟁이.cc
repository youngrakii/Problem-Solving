#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> h(9);
vector<int> selected;
bool found = false;

void dfs(int idx, int cnt, int sum) {
    // 이미 정답을 찾았으면 더 탐색 안 함
    if (found) return;

    // 7명을 다 골랐을 때
    if (cnt == 7) {
        if (sum == 100) {
            sort(selected.begin(), selected.end());
            for (int x : selected) {
                cout << x << '\n';
            }
            found = true;
        }
        return;
    }

    // 9명을 다 봤으면 종료
    if (idx == 9) return;

    // 현재 난쟁이 선택
    selected.push_back(h[idx]);
    dfs(idx + 1, cnt + 1, sum + h[idx]);
    selected.pop_back();

    // 현재 난쟁이 선택 안 함
    dfs(idx + 1, cnt, sum);
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> h[i];
    }

    dfs(0, 0, 0);

    return 0;
}