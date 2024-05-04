#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 1, 0 }; // 상 우 좌 하
int dy[] = { 0, 1, 0, -1 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(N, 0));

    int x = (N - 1) / 2; // 현재의 방향을 나타내는 iterator i를 2씩 감소
    int y = x;
    int cnt = 1;

    v[x][y] = cnt++;
    while (cnt <= N * N) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }
            if (v[nx][ny] != 0) { //0이 아니라면 채우기
                if (i == 0) i = 2;
                else if (i == 1) i = 3;
                else i -= 2;
            }
            else {
                v[nx][ny] = cnt++;
                x = nx; y = ny;
            }
        }
    }
    int ans_x, ans_y;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << v[i][j] << " ";
            if (v[i][j] == M) {
                ans_x = i + 1; ans_y = j + 1;
            }
        }
        cout << endl;
    }
    cout << ans_x << " " << ans_y;
    return 0;
}