#include <iostream>
#include <algorithm>

using namespace std;

long long N, result;
long long A[6];
long long a, b, c;

long long step1() {
    long long val = min(min(a, b), c);

    return val * ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2));
}

long long step2() {
    int val = min(min(a + b, b + c), c + a);

    return val * ((N - 1) * 4 + (N - 2) * 4);
}

long long step3() {
    int val = a + b + c;

    return val * 4;
}

void solution() {
    if (N == 1) {
        sort(A, A + 6);
        for (int i = 0; i < 5; i++) {
            result += A[i];
        }
    }
    else {
        a = min(A[0], A[5]);
        b = min(A[1], A[4]);
        c = min(A[2], A[3]);

        result = step1() + step2() + step3();
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < 6; i++) {
        cin >> A[i];
    }

    solution();

    return 0;
}