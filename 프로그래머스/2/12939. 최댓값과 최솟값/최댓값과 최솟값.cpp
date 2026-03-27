#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    vector<int> numbers;
    int num;
    
    while(ss>>num){
        numbers.push_back(num);
    }
    
    sort(numbers.begin(),numbers.end());
    
    return to_string(numbers.front())+" "+to_string(numbers.back());
}