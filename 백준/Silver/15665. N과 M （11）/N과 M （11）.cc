#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums, arr;

void dfs(int depth) {
    if (depth == M) {
        for (int x : arr) cout << x << ' ';
        cout << '\n';
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; i++) {
        if (nums[i] == prev) continue;

        arr.push_back(nums[i]);
        prev = nums[i];
        dfs(depth + 1);
        arr.pop_back();
    }
}

int main() {
    cin >> N >> M;
    nums.resize(N);

    for (int i = 0; i < N; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());

    dfs(0);
    return 0;
}