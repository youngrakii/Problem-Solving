#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> st;
	vector<char> result;
	int cnt = 1;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		while (cnt <= x) {
			st.push(cnt);
			cnt = cnt + 1;
			result.push_back('+');
		}

		if (st.top() == x) {
			st.pop();
			result.push_back('-');
		}
		else { cout << "NO"; return 0;}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}