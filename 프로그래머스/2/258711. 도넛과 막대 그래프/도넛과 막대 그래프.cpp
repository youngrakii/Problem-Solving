#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);

    // 정점 번호의 최댓값 찾기
    int maxNode = 0;
    for (const auto& e : edges) {
        maxNode = max(maxNode, max(e[0], e[1]));
    }

    // 진입차수, 진출차수 저장
    vector<int> indegree(maxNode + 1, 0);
    vector<int> outdegree(maxNode + 1, 0);

    for (const auto& e : edges) {
        int from = e[0];
        int to = e[1];
        outdegree[from]++;
        indegree[to]++;
    }

    int createdNode = 0;
    int stick = 0;   // 막대 그래프 개수
    int eight = 0;   // 8자 그래프 개수

    for (int i = 1; i <= maxNode; i++) {
        // 생성한 정점
        if (indegree[i] == 0 && outdegree[i] >= 2) {
            createdNode = i;
        }
        // 막대 그래프의 끝점
        else if (indegree[i] >= 1 && outdegree[i] == 0) {
            stick++;
        }
        // 8자 그래프의 중심점
        else if (indegree[i] >= 2 && outdegree[i] == 2) {
            eight++;
        }
    }

    int donut = outdegree[createdNode] - stick - eight;

    answer[0] = createdNode;
    answer[1] = donut;
    answer[2] = stick;
    answer[3] = eight;

    return answer;
}