#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<int> height(W);
    for (int i = 0; i < W; i++) {
        cin >> height[i];
    }

    int answer = 0;

    for (int i = 1; i < W - 1; i++) {
        int leftMax = 0;
        int rightMax = 0;

        // i의 왼쪽에서 가장 높은 벽 찾기
        for (int j = 0; j < i; j++) {
            leftMax = max(leftMax, height[j]);
        }

        // i의 오른쪽에서 가장 높은 벽 찾기
        for (int j = i + 1; j < W; j++) {
            rightMax = max(rightMax, height[j]);
        }

        int water = min(leftMax, rightMax) - height[i];

        if (water > 0) {
            answer += water;
        }
    }

    cout << answer << "\n";

    return 0;
}