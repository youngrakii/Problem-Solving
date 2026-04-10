#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;
    
    vector<unordered_set<int>> dp(9); // dp[i] : N을 i번 써서 만들 수 있는 수들
    
    for (int i = 1; i <= 8; i++) {
        int repeated = 0;
        
        // N, NN, NNN 형태의 수 만들기
        for (int k = 0; k < i; k++) {
            repeated = repeated * 10 + N;
        }
        dp[i].insert(repeated);
        
        // dp[j]와 dp[i-j]를 조합
        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) {
                        dp[i].insert(a / b);
                    }
                }
            }
        }
        
        // number를 만들 수 있으면 바로 반환
        if (dp[i].find(number) != dp[i].end()) {
            return i;
        }
    }
    
    return -1;
}