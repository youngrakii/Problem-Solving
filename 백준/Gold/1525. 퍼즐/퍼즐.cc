#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<long long int, long long int>;
using vi = vector<int>;
using vl = vector<long long int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long int>>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long int, long long int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using si = set<int>;
using sl = set<long long int>;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, b, e) for (int i = b; i < e; i++)
#define dcout cout << "debug: "


int nxt() {
	int input;
	cin >> input;
	return input;
}
ll nxtl() {
	ll input;
	cin >> input;
	return input;
}
string nxts() {
	string input;
	cin >> input;
	return input;
}
void printexit(ll a) {
	cout << a;
	exit(0);
}
void printyn(bool answer) {
	cout << (answer ? "Yes" : "No") << '\n';
}
int toint(vvi& x) {
	int res = 0, now = 1;
	rep(i, 0, 3) {
		rep(j, 0, 3) {
			res += now * x[i][j];
			now *= 9;
		}
	}
	return res;
}
vvi tovvi(int x) {
	vvi res(3, vi(3));
	rep(i, 0, 3) {
		rep(j, 0, 3) {
			res[i][j] = x % 9;
			x /= 9;
		}
	}
	return res;
}
void Solve(int Testcase_Number) {
	si vis;
	vvi fin = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
	vvi now(3, vi(3));
	rep(i, 0, 3) {
		rep(j, 0, 3) {
			now[i][j] = nxt();
		}
	}
	stack<int> q;
	q.push(toint(fin));
	vis.insert(toint(fin));
	int cnt = 0;
	while (q.size()) {
		stack<int> nq;
		while (q.size()) {
			auto tmp = q.top();
			q.pop();
			auto x = tovvi(tmp);
			if (x == now) {
				cout << cnt;
				return;
			}
			rep(i, 0, 3) {
				rep(j, 0, 3) {
					if (x[i][j]) continue;
					for (int d = -3; d < 4; d += 2) {
						int dx = i + d % 3, dy = j + d / 2;
						if (dx < 0 || dx > 2 || dy < 0 || dy > 2) continue;
						swap(x[i][j], x[dx][dy]);
						int y = toint(x);
						if (!vis.count(y)) {
							nq.push(y);
							vis.insert(y);
						}
						swap(x[i][j], x[dx][dy]);
					}
				}
			}
		}
		swap(q, nq);
		cnt++;
	}
	cout << -1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int tc = 1;
	rep(i, 0, tc) {
		Solve(i + 1);
	}
}
