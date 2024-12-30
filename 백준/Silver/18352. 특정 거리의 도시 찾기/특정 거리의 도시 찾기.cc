#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl "\n";
#define INF 2000000000 //처음에 x점까지의 최단거리

using namespace std;

vector<int> graph[300001];

vector<int> diijkstra(int vertex, int start) {
	vector<int> distance(vertex, INF);
	distance[start] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (pq.size() > 0) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (distance[cur] < cost) {
			continue;
		}

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			int nCost = 1;

			if (distance[next] < nCost + cost) {
				continue;
			}

			distance[next] = nCost + cost;
			pq.push(make_pair(nCost + cost, next));
		}
	}

	return distance;

}

int main() {
	cin.tie(0);
	cout.tie(0);
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	n++;
	for (int i = 0; i < m; i++) {
		int source, destination;
		cin >> source >> destination;
		graph[source].push_back(destination);
	}
	vector<int> answer = diijkstra(n, x);
	int count = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == k) {
			count++;
			cout << i << endl;
		}
	}
	if (count == 0) {
		cout << -1 << endl;
	}

	return 0;
}