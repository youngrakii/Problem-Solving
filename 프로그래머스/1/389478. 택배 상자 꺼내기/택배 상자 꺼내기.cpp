#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int r = (num-1)/w;
    int p = (num-1)%w;
    
    int x = (r%2==0)?p:(w-1-p);
    
    int top_row = (n-1)/w;
    
    for(int u=r; u<=top_row; u++){
        int row_size;
        if(u<top_row) row_size = w;
        else row_size = n-w*top_row;
        
        bool occupied;
        if(u%2==0){
            occupied = (x<row_size);
        }else{
            occupied = (x>=w-row_size);
        }
        
        if(occupied) answer++;
    }
    return answer;
}