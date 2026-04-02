#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void dfs(int depth) {
    if (depth == M) {
        for (int x : arr) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        arr.push_back(i);
        dfs(depth + 1);
        arr.pop_back();
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
    return 0;
}