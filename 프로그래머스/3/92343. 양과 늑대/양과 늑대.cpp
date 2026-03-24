#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> children[18];
int answer=0;

void dfs(int sheep, int wolf, int current, vector<int> nextNodes, vector<int>& info){
    //현재 노드 방문
    if(info[current]==0) sheep++;
    else wolf++;
    
    //늑대 수가 양의 수 이상이면 종료
    if(wolf>=sheep) return;
    
    //최대 양 수 갱신
    answer = max(answer, sheep);
    
    //현재 노드는 후보 목록에서 제거
    vector<int> candidates;
    for(int node:nextNodes){
        if(node!=current){
            candidates.push_back(node);
        }
    }
    
    //현재 노드의 자식들을 후보 목록에 추가
    for(int child:children[current]){
        candidates.push_back(child);
    }
    
    //다음 후보들에 대해 탐색
    for(int node:candidates){
        dfs(sheep, wolf, node, candidates,info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
   // for(int i=0; i<18; i++){
   //     children[i].clear();
   // }
   // answer=0;
    
    for(auto edge:edges){
        children[edge[0]].push_back(edge[1]);
    }
    
    vector<int> nextNodes;
    nextNodes.push_back(0); //시작은 0번 노드
    
    dfs(0,0,0,nextNodes,info);
    return answer;
}