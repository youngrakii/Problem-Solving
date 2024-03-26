#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int n;
string str[1000];
int integer_sum(string str) {
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] - '0' <= 9 && str[i] - '0' >= 0) {
			sum += str[i] - '0';
		}
	}
	return sum;
}
bool compare(string a, string b) {
	int sum_a = integer_sum(a);
	int sum_b = integer_sum(b);
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() > b.length()) {
		return false;
	}
	else if (sum_a > sum_b) {
		return 0;
	}
	else {
		if (sum_a > sum_b) {
			return 0;
		}
		else if (sum_a < sum_b) {
			return 1;
		}
		else {
			return a < b;
		}
	}
}
int main() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		sort(str, str + n, compare);
		for (int i = 0; i < n; i++) {
			cout << str[i] << "\n";
		}
}