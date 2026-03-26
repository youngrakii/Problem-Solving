#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int M, N;
    cin >> M >> N;

    int sum = 0;
    int minPrime = -1;

    for (int i = M; i <= N; i++) {
        if (isPrime(i)) {
            sum += i;
            if (minPrime == -1) minPrime = i;
        }
    }

    if (minPrime == -1) {
        cout << -1 << "\n";
    } else {
        cout << sum << "\n";
        cout << minPrime << "\n";
    }

    return 0;
}