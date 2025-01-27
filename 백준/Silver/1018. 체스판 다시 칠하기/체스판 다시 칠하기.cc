#include <iostream>

using namespace std;

char chess[51][51];
char white_board[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};
char black_board[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};

int cmp_white(int x, int y) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[x + i][y + j] != white_board[i][j])
				result++;
		}
	}
	return result;
}

int cmp_black(int x, int y) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess[x + i][y + j] != black_board[i][j])
				result++;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
	int N, M;
	int answer = 64;
	cin >> N >> M;
    
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chess[i][j];
		}
	}
    
	int cnt_white = 0;
	int cnt_black = 0;
    
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			cnt_white = cmp_white(i, j);
			cnt_black = cmp_black(i, j);
			if (cnt_white < cnt_black) {
				if (cnt_white < answer) {
					answer = cnt_white;
				}
			}
			else {
				if (cnt_black < answer)
					answer = cnt_black;
			}
		}
	}
	cout << answer << '\n';
}