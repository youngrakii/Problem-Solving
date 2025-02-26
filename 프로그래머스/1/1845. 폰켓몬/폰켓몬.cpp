#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums){
    int answer=0;
    int cnt=0;
    unordered_set<int> us;
    
    for(int i=0; i<nums.size(); i++){
        us.insert(nums[i]);
    }
    
    if(nums.size()/2 < us.size()){
        answer=nums.size()/2;
    }
    else answer=us.size();
    
    return answer;
}