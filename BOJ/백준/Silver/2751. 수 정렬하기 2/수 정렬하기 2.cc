#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> num(n);
	for (auto &k : num) cin >> k;

	sort(num.begin(), num.end());

	for (auto k : num) cout << k << "\n";
}
