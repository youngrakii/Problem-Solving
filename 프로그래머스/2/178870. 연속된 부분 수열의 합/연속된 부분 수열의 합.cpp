#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    
    int left =0;
    int sum=0;
    
    int bestLeft=0;
    int bestRight=n-1;
    int bestLength=n+1;
    
    for(int right=0; right<n; right++){
        sum+=sequence[right];
        
        while(sum>k && left<=right){
            sum-=sequence[left];
            left++;
        }
        
        if(sum==k){
            int length = right-left;
            if(length<bestLength){
                bestLength = length;
                bestLeft = left;
                bestRight = right;
            }
        }
    }
    
    return {bestLeft,bestRight};
}