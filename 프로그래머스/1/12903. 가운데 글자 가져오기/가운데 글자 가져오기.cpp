#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int k = s.length()-1;
    int m =k/2;
    if(k%2==0){
        answer+=s[m];
    }
    else{
        answer+=s[m];
        answer+=s[m+1];
    }
    return answer;
}