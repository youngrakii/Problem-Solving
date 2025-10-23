#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

// 다익스트라: 시작점 s에서 각 정점까지 최단거리, 그리고 가장 먼 정점 인덱스 반환
pair<int, vector<ll>> dijkstra(int s, const vector<vector<pair<int, int>>>& g) {
    int N = (int)g.size() - 1;
    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            ll nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({ nd, v });
            }
        }
    }
    int far = 1;
    for (int i = 2; i <= N; ++i)
        if (dist[i] < INF && dist[i] > dist[far]) far = i;

    return { far, dist };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<pair<int, int>>> g(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({ b, w });
        g[b].push_back({ a, w });
    }

    if (N == 1) { cout << 0 << '\n'; return 0; }

    // 1) 임의의 정점(1)에서 가장 먼 정점 u
    auto [u, d1] = dijkstra(1, g);
    // 2) u에서 가장 먼 거리 = 지름
    auto [v, d2] = dijkstra(u, g);

    ll diameter = 0;
    for (int i = 1; i <= N; ++i) diameter = max(diameter, d2[i]);
    cout << diameter << '\n';
    return 0;
}
