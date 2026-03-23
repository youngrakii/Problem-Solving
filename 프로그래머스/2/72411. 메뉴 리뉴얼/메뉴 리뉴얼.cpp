#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string,int> combi_map;

void combine(string order, string temp, int idx, int target_len){
    if(temp.length()==target_len){
        combi_map[temp]++;
        return;
      
    }
    for(int i=idx; i<order.length(); i++){
        combine(order,temp+order[i],i+1,target_len);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int len:course){
        combi_map.clear();
        for(string order:orders){
            sort(order.begin(),order.end());
            if(order.length()>=len){
                combine(order,"",0,len);
            }
        }
        
        int max_val=0;
        for(auto it:combi_map){
            max_val = max(max_val, it.second);
        }
        
        if(max_val>=2){
            for(auto it:combi_map){
                if(it.second == max_val){
                    answer.push_back(it.first);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}