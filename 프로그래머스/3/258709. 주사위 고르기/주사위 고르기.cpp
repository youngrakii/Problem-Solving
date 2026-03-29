#include <vector>
#include <algorithm>

using namespace std;

vector<int> bestAnswer;
long long maxWin = -1;

void makeSums(const vector<vector<int>>& dice, const vector<int>& selected, int idx, int sum, vector<int>& sums) {
    if (idx == selected.size()) {
        sums.push_back(sum);
        return;
    }

    int diceIdx = selected[idx];
    for (int i = 0; i < 6; i++) {
        makeSums(dice, selected, idx + 1, sum + dice[diceIdx][i], sums);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int half = n / 2;

    vector<int> pick(n, 0);
    for (int i = n - half; i < n; i++) {
        pick[i] = 1;
    }

    do {
        vector<int> A, B;

        for (int i = 0; i < n; i++) {
            if (pick[i] == 1) A.push_back(i);
            else B.push_back(i);
        }

        vector<int> sumsA, sumsB;
        makeSums(dice, A, 0, 0, sumsA);
        makeSums(dice, B, 0, 0, sumsB);

        sort(sumsB.begin(), sumsB.end());

        long long win = 0;
        for (int x : sumsA) {
            win += lower_bound(sumsB.begin(), sumsB.end(), x) - sumsB.begin();
        }

        if (win > maxWin) {
            maxWin = win;
            bestAnswer.clear();
            for (int idx : A) {
                bestAnswer.push_back(idx + 1);
            }
        }

    } while (next_permutation(pick.begin(), pick.end()));

    return bestAnswer;
}