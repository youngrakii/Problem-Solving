#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int N;
std::string S;
std::unordered_map <std::string, int> Map;

void Solve() {
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> S;
		if (Map[S] == 0) Map[S]++;
		else {
			std::cout << S.length() << " " << S[S.length() / 2];
			return;
		}
		std::reverse(S.begin(), S.end());
		if (Map[S] == 0) Map[S]++;
		else {
			std::cout << S.length() << " " << S[S.length() / 2];
			return;
		}
	}
}

int main() {
	Solve();
}