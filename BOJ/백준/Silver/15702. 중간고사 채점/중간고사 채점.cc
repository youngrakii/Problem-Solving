#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& front, pair<int, int>& back) {
	if (front.second < back.second) {
		return front.second > back.second;
	}
	else if (front.second == back.second) {
		return front.first < back.first;
	}
	else {
		return front.second > back.second;
	}

}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}

	int sn;
	char ox;
	vector<pair<int, int>> w;
	for (int i = 0; i < m; i++) {
		int score = 0;
		cin >> sn;
		for (int j = 0; j < n; j++) {
			cin >> ox;
			if (ox == 'O') {
				score += v[j];
			}
			w.push_back({ sn,score });
		}
	}
	sort(w.begin(), w.end(), compare);
	cout << w[0].first << " " << w[0].second;
	return 0;
}