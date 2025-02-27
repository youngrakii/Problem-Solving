#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    while (N--) {
        priority_queue<int, vector<int>, greater<int>> min_queue;
        priority_queue<int, vector<int>, less<int>> max_queue;
        map<int, int> test;

        int coun;
        cin >> coun;

        for (int j = 0; j < coun; j++) {
            char a;
            int b;
            cin >> a >> b;

            if (a == 'I') {
                min_queue.push(b);
                max_queue.push(b);
                test[b]++;
            }

            if (a == 'D') {
                if (b == 1) {
                    // 최댓값 삭제
                    while (!max_queue.empty() && test[max_queue.top()] == 0) {
                        max_queue.pop();
                    }
                    if (!max_queue.empty()) {
                        test[max_queue.top()]--;
                        max_queue.pop();
                    }
                } else if (b == -1) {
                    // 최솟값 삭제
                    while (!min_queue.empty() && test[min_queue.top()] == 0) {
                        min_queue.pop();
                    }
                    if (!min_queue.empty()) {
                        test[min_queue.top()]--;
                        min_queue.pop();
                    }
                }
            }
        }

        // 유효한 최댓값, 최솟값 정리
        while (!max_queue.empty() && test[max_queue.top()] == 0) {
            max_queue.pop();
        }
        while (!min_queue.empty() && test[min_queue.top()] == 0) {
            min_queue.pop();
        }

        // 출력
        if (max_queue.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_queue.top() << " " << min_queue.top() << "\n";
        }
    }
}
