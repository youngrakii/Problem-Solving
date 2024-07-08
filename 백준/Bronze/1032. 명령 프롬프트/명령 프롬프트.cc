#include <iostream>
#include <string>
using namespace std;
int main() {
	int N;
	cin >> N;

	string sen;
	string newsen;
	cin >> sen;
	for (int i = 0; i < N - 1; i++) {
		cin >> newsen;
		for (int j = 0; j < sen.length(); j++) {
			if (sen[j] != newsen[j])
				sen[j] = '?';
		}
	}
	cout << sen;
	return 0;
}