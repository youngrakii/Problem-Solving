#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct State {
    int x1, y1, x2, y2;
    
    bool operator<(const State& other) const {
        if (x1 != other.x1) return x1 < other.x1;
        if (y1 != other.y1) return y1 < other.y1;
        if (x2 != other.x2) return x2 < other.x2;
        return y2 < other.y2;
    }
};

struct Robot {
    int x1, y1, x2, y2, dist;
};

State normalize(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || (x1 == x2 && y1 > y2)) {
        swap(x1, x2);
        swap(y1, y2);
    }
    return {x1, y1, x2, y2};
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    
    queue<Robot> q;
    set<State> visited;
    
    q.push({0, 0, 0, 1, 0});
    visited.insert(normalize(0, 0, 0, 1));
    
    while (!q.empty()) {
        Robot cur = q.front();
        q.pop();
        
        int x1 = cur.x1, y1 = cur.y1;
        int x2 = cur.x2, y2 = cur.y2;
        int dist = cur.dist;
        
        if ((x1 == n - 1 && y1 == n - 1) || (x2 == n - 1 && y2 == n - 1)) {
            return dist;
        }
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        for (int dir = 0; dir < 4; dir++) {
            int nx1 = x1 + dx[dir];
            int ny1 = y1 + dy[dir];
            int nx2 = x2 + dx[dir];
            int ny2 = y2 + dy[dir];
            
            if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n ||
                nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n) continue;
            if (board[nx1][ny1] == 1 || board[nx2][ny2] == 1) continue;
            
            State nextState = normalize(nx1, ny1, nx2, ny2);
            if (visited.count(nextState)) continue;
            
            visited.insert(nextState);
            q.push({nx1, ny1, nx2, ny2, dist + 1});
        }
        
        if (x1 == x2) {
            for (int d : {-1, 1}) {
                int nx = x1 + d;
                if (nx < 0 || nx >= n) continue;
                if (board[nx][y1] == 1 || board[nx][y2] == 1) continue;
                
                State s1 = normalize(x1, y1, nx, y1);
                if (!visited.count(s1)) {
                    visited.insert(s1);
                    q.push({x1, y1, nx, y1, dist + 1});
                }
                
                State s2 = normalize(x2, y2, nx, y2);
                if (!visited.count(s2)) {
                    visited.insert(s2);
                    q.push({x2, y2, nx, y2, dist + 1});
                }
            }
        } else {
            for (int d : {-1, 1}) {
                int ny = y1 + d;
                if (ny < 0 || ny >= n) continue;
                if (board[x1][ny] == 1 || board[x2][ny] == 1) continue;
                
                State s1 = normalize(x1, y1, x1, ny);
                if (!visited.count(s1)) {
                    visited.insert(s1);
                    q.push({x1, y1, x1, ny, dist + 1});
                }
                
                State s2 = normalize(x2, y2, x2, ny);
                if (!visited.count(s2)) {
                    visited.insert(s2);
                    q.push({x2, y2, x2, ny, dist + 1});
                }
            }
        }
    }
    
    return -1;
}