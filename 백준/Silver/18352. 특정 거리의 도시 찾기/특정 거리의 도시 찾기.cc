#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#define INF 987654321

using namespace std;

queue<pair<int, int>> q;
vector<pair<int, int>> line[300001];
int check[300001];
int Distance[300001];
int N, M, K, start;

void bfs(int x) {
	Distance[x] = 0;
	q.push({ 0,x });
	while (!q.empty()) {
		int X = q.front().second;
		int cost = q.front().first;
		check[X] = 1;
		q.pop();
		for (int i = 0; i < line[X].size(); i++) {
			int xx = line[X][i].first;
			int Cost = line[X][i].second;
			if (check[xx] == 0) {
				if (Distance[xx] > Distance[X] + Cost) {
					Distance[xx] = Distance[X] + Cost;
					q.push({ Distance[xx],xx });
				}
			}
		}
	}
}

void solve() {
	vector<int> point;
	for (int i = 1; i <= N; i++) Distance[i] = INF;
	bfs(start);
	for (int i = 1; i <= N; i++) {
		if (Distance[i] == K) {
			point.push_back(i);
		}
	}
	if (point.size() == 0) cout << "-1";
	else {
		sort(point.begin(), point.end());
		for (int i = 0; i < point.size(); i++) {
			cout << point[i] << "\n";
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K >> start;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		line[x].push_back({ y,1 });
	}
	solve();
	return 0;
}