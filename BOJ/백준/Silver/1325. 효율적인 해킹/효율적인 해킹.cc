// BFS를 위한 queue인 reservation과, 방문여부를 나타낼 vector인 visited 생성 및 초기화.
// counter변수인 cnt를 0으로 초기화한 뒤, 초기값 i를 reservation에 삽입해 BFS순회 시작.
// BFS완료 뒤 cnt를 v에 추가
// i는 1번부터지만, v는 push_back 하였기때문에 0부터 시작.
//감염시킨 컴퓨터 수의 최대치를 판별
// v의 0번쨰 인덱스는 사실 1번째 컴퓨터에 해당하는 것이므로 1을 더해주어 출력
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> graph[10001];
bool visited[10001];
int n,m,cnt;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	}
};


void dfs(int start) {
// 입력받아 컴퓨터간의 신뢰관계를 나타내는 그래프를 작성
	cnt++;
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {

		if (!visited[graph[start][i]]) {
			
			dfs(graph[start][i]);
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	for (int i = 0; i < m; i++) {
		int to, from;
		cin >> to >> from;
		graph[from].push_back(to);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
		pq.push({ cnt,i });
		//cout << i << ' ' << cnt << '\n';
		cnt = 0;
		memset(visited, false, sizeof(visited));
	}
	if (!pq.empty()) {
		int first = pq.top().first;
		int result = pq.top().second;
		cout << result << ' ';
		pq.pop();
		while (!pq.empty()&& first==pq.top().first) {
			cout << pq.top().second << ' ';
			pq.pop();
		}
	}

	return 0;
}