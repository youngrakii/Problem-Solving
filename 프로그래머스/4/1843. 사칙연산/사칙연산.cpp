#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<string> arr) {
    vector<int> nums;
    vector<char> ops;
    
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) nums.push_back(stoi(arr[i]));
        else ops.push_back(arr[i][0]);
    }
    
    int n = nums.size();
    
    vector<vector<int>> dpMax(n, vector<int>(n, INT_MIN));
    vector<vector<int>> dpMin(n, vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; i++) {
        dpMax[i][i] = nums[i];
        dpMin[i][i] = nums[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            
            for (int k = i; k < j; k++) {
                char op = ops[k];
                
                if (op == '+') {
                    dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] + dpMax[k + 1][j]);
                    dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] + dpMin[k + 1][j]);
                } else {
                    dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] - dpMin[k + 1][j]);
                    dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] - dpMax[k + 1][j]);
                }
            }
        }
    }
    
    return dpMax[0][n - 1];
}