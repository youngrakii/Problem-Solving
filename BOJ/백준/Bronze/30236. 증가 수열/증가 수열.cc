#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int _ = 0; _ < N; ++_) {
        int n;
        cin >> n;
        vector<int> temp(n);
        vector<int> lst(n);

        for (int i = 0; i < n; ++i) {
            temp[i] = i + 1;
        }

        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }

        for (int i = 0; i < n; ++i) {
            if (temp[i] == lst[i]) {
                temp[i] += 1;
            }

            for (int j = i + 1; j < n; ++j) {
                if (temp[j - 1] >= temp[j]) {
                    temp[j] += (temp[j - 1] - temp[j]) + 1;
                }
            }
        }

        cout << temp[n - 1] << endl;
    }
    return 0;
}
