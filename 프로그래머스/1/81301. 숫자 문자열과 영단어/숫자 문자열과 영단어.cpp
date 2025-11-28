#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string numberString; // 최종적으로 "1478" 같은 순수 숫자 문자열을 만들기 위한 변수
    string word;         // 알파벳(영단어)들을 잠시 모아두는 버퍼

    for (char c : s) {
        // 1) 숫자인 경우 그대로 결과 문자열에 추가
        if ('0' <= c && c <= '9') {
            numberString += c;
        }
        // 2) 알파벳인 경우 word 버퍼에 하나씩 쌓으면서 어떤 숫자 단어인지 확인
        else {
            word += c;

            if (word == "zero")   { numberString += '0'; word.clear(); }
            else if (word == "one")   { numberString += '1'; word.clear(); }
            else if (word == "two")   { numberString += '2'; word.clear(); }
            else if (word == "three") { numberString += '3'; word.clear(); }
            else if (word == "four")  { numberString += '4'; word.clear(); }
            else if (word == "five")  { numberString += '5'; word.clear(); }
            else if (word == "six")   { numberString += '6'; word.clear(); }
            else if (word == "seven") { numberString += '7'; word.clear(); }
            else if (word == "eight") { numberString += '8'; word.clear(); }
            else if (word == "nine")  { numberString += '9'; word.clear(); }
        }
    }

    // 완성된 숫자 문자열을 정수로 변환
    int answer = stoi(numberString);
    return answer;
}
