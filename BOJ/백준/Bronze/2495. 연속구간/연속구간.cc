#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	for (int i = 0; i < 3; i++) {
		cin >> str;
		int cnt = 1;
		int max = 1;
		for (int i = 0; i < str.length() - 1; i++) {
			if (str[i] == str[i + 1]) {
				cnt++;
				if (cnt > max) {
					max = cnt;
				}
			}
			else {
				cnt = 1;
			}
		}
		cout << max << "\n";
	}
}