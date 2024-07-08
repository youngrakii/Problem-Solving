#include <iostream>
using namespace std;

long long N, B;
long long matrix[5][5];
long long ans[5][5];

void input() {
	// N : 행렬의 크기, B :  거듭제곱 횟수
	cin >> N >> B;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> matrix[y][x];
		}
		ans[y][y] = 1;	// 단위행렬 입력
	}
}

// 두 행렬을 곱하는 함수
void multi_matrix(long long matrix1[5][5], long long matrix2[5][5]) {
	long long tmp[5][5];

	// 행렬 곱 계산
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			long long sum = 0;

			for (int i = 0; i < N; i++) {
				sum += matrix1[y][i] * matrix2[i][x];
			}

			tmp[y][x] = sum % 1000;		// 1000으로 나누기
		}
	}

	// 임시행렬 값을 Matrix1에 덮어씌우기
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			matrix1[y][x] = tmp[y][x];
}

void solve() {
	while (B > 0) {
		// 홀수일 경우, ans와 matrix 곱
		if (B % 2 == 1)
			multi_matrix(ans, matrix);

		// matrix 거듭제곱
		multi_matrix(matrix, matrix);
		B /= 2;
	}
}

// 행렬 출력하는 함수
void print_matrix(long long matrix1[5][5]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << matrix1[y][x] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	print_matrix(ans);

	return 0;
}
