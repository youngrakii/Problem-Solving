#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    vector<int> numbers;
    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }
    
    vector<vector<int>> candidates;
    vector<int> combination;
    
    // 모든 가능한 5개의 숫자 조합을 생성
    function<void(int)> generateCombinations = [&](int start) {
        if (combination.size() == 5) {
            candidates.push_back(combination);
            return;
        }
        for (int i = start; i < n; i++) {
            combination.push_back(numbers[i]);
            generateCombinations(i + 1);
            combination.pop_back();
        }
    };
    generateCombinations(0);
    
    // 각 조합이 주어진 조건을 만족하는지 확인
    for (const auto& candidate : candidates) {
        bool isValid = true;
        for (size_t i = 0; i < q.size(); i++) {
            int matchCount = 0;
            for (int num : q[i]) {
                if (find(candidate.begin(), candidate.end(), num) != candidate.end()) {
                    matchCount++;
                }
            }
            if (matchCount != ans[i]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            answer++;
        }
    }
    
    return answer;
}
