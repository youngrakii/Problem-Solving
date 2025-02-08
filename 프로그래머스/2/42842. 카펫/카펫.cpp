#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total_size = brown + yellow; // 카펫의 면적
    
    for(int i=3; i<total_size/2; ++i){
        if(total_size%i != 0) continue;
        
        int width = i;
        int height = total_size/i;
        
        if(width*2 + height*2 - 4 ==brown){
            answer.push_back(max(width,height));
            answer.push_back(min(width,height));
            break;
        }
    }
    
    
    return answer;
}