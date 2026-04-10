#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string result = "";
    
    for (char c : number) {
        while (!result.empty() && k > 0 && result.back() < c) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }
    
    // 아직 제거해야 할 개수가 남아 있으면 뒤에서 제거
    result.resize(result.size()-k);
    
    return result;
}