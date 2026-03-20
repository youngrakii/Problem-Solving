#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for (int i=1; i<=s.size() / 2; i++) {
        int cnt = 1;
        string temp = "";
        string compareStr = s.substr(0, i);
        
        for (int j=i; j<s.size(); j+=i) {
            string currentStr = s.substr(j, i);
            if (compareStr == currentStr) cnt++;
            else {
                if (cnt > 1) temp += to_string(cnt);
                temp += compareStr;
                compareStr = currentStr;
                cnt = 1;
            }
        }
        
        if (cnt > 1) temp += to_string(cnt);
        temp += compareStr;
        answer = answer > temp.size() ? temp.size() : answer;
    }
    
    return answer;
}