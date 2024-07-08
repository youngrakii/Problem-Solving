#include <iostream>
#define MAX_N 101
#define DIR_NUM 4

using namespace std;

int n, m;
int cnt = 1;
int arr[MAX_N][MAX_N];

int dx[DIR_NUM] = { 0, 1, 0, -1 };
int dy[DIR_NUM] = { 1, 0, -1, 0 };

int curr_x = 0, curr_y = 0;
int dir = 0;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    cin >> n >> m;
    arr[curr_x][curr_y] = 1;

    for (int i = 2; i <= n * m; i++) {
        int next_x = curr_x + dx[dir];
        int next_y = curr_y + dy[dir];

        if (!InRange(next_x, next_y) || arr[next_x][next_y] != 0) {
            dir = (dir + 1) % DIR_NUM;
            cnt++;
        }
        curr_x += dx[dir];
        curr_y += dy[dir];
        arr[curr_x][curr_y] = 1;
    }

    cout << cnt-1;
    return 0;
}