#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s){
    int answer = s.size();
    
    for(int i=1; i<=s.size()/2; i++){
        string compressed = "";
        string prev = s.substr(0,i);
        int cnt = 1;
        
        for(int j=i; j<s.size(); j+=i){
            string cur = s.substr(j,i);
            
            if(prev == cur) cnt++;
            else{
                if(cnt>=2) compressed += to_string(cnt);
                compressed +=prev;
                prev = cur;
                cnt=1;
            }
        }
        
        if(cnt>=2) compressed+=to_string(cnt);
        compressed+=prev;
        
        answer = min(answer, (int)compressed.size());
    }
    
    return answer;
}