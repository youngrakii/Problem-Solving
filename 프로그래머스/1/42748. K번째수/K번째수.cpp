#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    //반환되어야 하는 세트동안 반복
    for(int i=0; i<commands.size(); i++){
        
        //임시 벡터 생성
        vector<int> temp;
        
        //필요한 부분만 임시 벡터에 넣음
        for(int j=commands[i][0]-1; j<commands[i][1];j++){
            temp.push_back(array[j]);
        }
        
        //임시 벡터 정렬
        sort(temp.begin(),temp.end());
        
        //임시 벡터의 index번째를 answer에 넣음
        answer.push_back(temp[commands[i][2]-1]);
    }
    
    return answer;
}