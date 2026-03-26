#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int x;
    cin >> x;

    int minValue = x;
    int maxValue = x;

    for (int i = 1; i < N; i++) {
        cin >> x;

        if (x < minValue) minValue = x;
        if (x > maxValue) maxValue = x;
    }

    cout << minValue << " " << maxValue << "\n";

    return 0;
}