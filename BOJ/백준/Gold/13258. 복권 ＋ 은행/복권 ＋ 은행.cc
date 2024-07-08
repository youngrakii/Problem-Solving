#include <iostream>
#include <vector>
#include <iomanip> // for std::setprecision

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> numbers(N);
    int sum = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
        sum += numbers[i];
    }
    
    double J, C;
    cin >> J >> C;
    
    // 첫 번째 숫자
    int num = numbers[0];
    
    // 적어도 한 사람의 잔고는 0원보다 많기 때문에 sum이 0이 되는 경우는 없다.
    double ans = num + (num * J * C) / sum;
    
    // 소수점 아래 10자리까지 출력
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}


/*함수 f(n)을 n개의 사탕이 남았을때, 던져야하는 주사위횟수의 기댓값이라고 정의를 합시다.

for문을 보면, 주사위의 면이(1~6) 나왔을때의 기댓값을 모두 더하고있습니다. 

주사위의 면이 1이나왔을때, 사탕은 n-1개가 남았을것이고, 주사위 던지는횟수가 1회 늘었으므로 f(n-i)+1입니다.*/

