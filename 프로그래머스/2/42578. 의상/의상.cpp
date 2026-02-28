#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0; // 최종 조합 수를 저장할 변수
    
    unordered_map<string, vector<string>> m; // 의상 종류별로 의상을 저장할 맵
    
    // 의상을 종류별로 그룹화합니다.
    for(auto v : clothes)
    {
        m[v[1]].push_back(v[0]); // 종류를 키로, 의상 이름을 값으로 추가
    }
    
    int temp = 1; // 조합 수를 계산하기 위한 변수
    // 각 종류별로 가능한 조합 수를 계산합니다.
    for(auto p : m)
    {
        temp *= p.second.size() + 1; // 각 의상 종류에서 착용하지 않는 경우를 포함하여 곱합니다.
    }
    
    return temp - 1; // 최소 한 개의 의상은 착용하므로 1을 빼줍니다.
}