#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, m;
		long long ans = 1;
		cin >> n >> m;
		int r = 1;
		for (int i = m; i >m-n; i--) {
			ans = ans * i;
			ans = ans / r;
			r++;
		}
		cout << ans << "\n";
	}

}