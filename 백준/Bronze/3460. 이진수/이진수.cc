#include <iostream>
using namespace std;

int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin>>N;
        for (int i = 0; i <=20; i++) {  // 0 ~ 19번째 비트 확인
            if (N & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}