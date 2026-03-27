#include <string>
#include <vector>
#include <set>

using namespace std;

struct Edge {
    int x1, y1, x2, y2;
    
    bool operator<(const Edge& other) const {
        if (x1 != other.x1) return x1 < other.x1;
        if (y1 != other.y1) return y1 < other.y1;
        if (x2 != other.x2) return x2 < other.x2;
        return y2 < other.y2;
    }
};

int solution(vector<int> arrows) {
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    set<pair<int, int>> visitedNode; // 방문한 정점
    set<Edge> visitedEdge;           // 방문한 간선
    
    int x = 0, y = 0;
    int answer = 0;
    
    visitedNode.insert({x, y});
    
    for (int dir : arrows) {
        // 대각선 교차 처리를 위해 2번 이동
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            Edge e1 = {x, y, nx, ny};
            Edge e2 = {nx, ny, x, y}; // 반대 방향도 같은 간선으로 처리
            
            // 이미 방문한 정점인데, 간선은 처음 방문이면 방이 생김
            if (visitedNode.count({nx, ny}) && !visitedEdge.count(e1)) {
                answer++;
            }
            
            visitedNode.insert({nx, ny});
            visitedEdge.insert(e1);
            visitedEdge.insert(e2);
            
            x = nx;
            y = ny;
        }
    }
    
    return answer;
}