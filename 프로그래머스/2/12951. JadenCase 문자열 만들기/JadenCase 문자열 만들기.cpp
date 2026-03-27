#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    bool isFirst = true;  // 현재 문자가 단어의 첫 글자인지
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isFirst = true;
        } 
        else {
            if (isFirst) {
                s[i] = toupper(s[i]);
                isFirst = false;
            } else {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    return s;
}