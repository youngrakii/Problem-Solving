#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long m, n;
    cin >> m >> n;

    if (m > n) {
        // m이 n보다 큰 경우
        printf("%ld\n", 2 * (n - 1) + 1);
    } else {
        printf("%ld\n", 2 * (m - 1));
    }

    if (m == n) {
        if (m % 2 == 1) {
            printf("%ld %ld", (m - 1) / 2 + 1, (m - 1) / 2 + 1);
        } else {
            printf("%ld %ld", m / 2 + 1, m / 2);
        }
    } else {
        if (n > m) {
            if (m % 2 == 0) {
                printf("%ld %ld", m / 2 + 1, m / 2);
            } else {
                printf("%ld %ld", m / 2 + 1, m / 2 + 1 + (n - m));
            }
        } else {
            if (n % 2 == 0) {
                printf("%ld %ld", n / 2 + 1, n / 2);
            } else {
                printf("%ld %ld", n / 2 + 1 + (m - n), n / 2 + 1);
            }
        }
    }

    return 0;
}
