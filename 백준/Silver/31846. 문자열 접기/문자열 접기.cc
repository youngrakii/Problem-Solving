#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 주어진 구간에서 접었을 때 맞닿는 같은 문자 쌍의 개수를 계산하는 함수
int calculate_score(const string& str, int l, int r, int fold_position) {
    int left = fold_position - 1;
    int right = fold_position;
    int score = 0;

    // 왼쪽과 오른쪽에서 맞닿는 문자들을 비교
    while (left >= l && right <= r) {
        if (str[left] == str[right]) {
            score++;
        }
        left--;
        right++;
    }
    return score;
}

int main() {
    int N, Q;
    cin >> N;
    string S;
    cin >> S;
    cin >> Q;

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (const auto& query : queries) {
        int l = query.first - 1;
        int r = query.second - 1;

        int max_score = 0;
        for (int i = l + 1; i <= r; ++i) {
            int score = calculate_score(S, l, r, i);
            if (score > max_score) {
                max_score = score;
            }
        }

        cout << max_score << endl;
    }

    return 0;
}
