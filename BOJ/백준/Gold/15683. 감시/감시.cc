#include <iostream>
#define endl '\n'

using namespace std;

struct CCTV {
	int type, r, c;
};
int N, M, ans = 1e9, map[8][8];
int cctv_size;
CCTV cctv[8];
const int rotation[] = { NULL, 4, 2, 4, 4,1 };

void map_cpy(int desc[8][8], int src[8][8]) {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			desc[r][c] = src[r][c];
		}
	}
}

void update(int dir, CCTV cctv) {
	dir %= 4;
	if (dir == 0) {
		for (int c = cctv.c + 1; c < M; c++){
			if (map[cctv.r][c] == 6) break;
			map[cctv.r][c] = -1;
		}
	}

	else if (dir == 1) {
		for (int r = cctv.r - 1; r >= 0; r--) {
			if (map[r][cctv.c] == 6) break;
			map[r][cctv.c] = -1;
		}
	}

	else if (dir == 2) {
		for (int c = cctv.c - 1; c >= 0; c--) {
			if (map[cctv.r][c] == 6) break;
			map[cctv.r][c] = -1;
		}
	}

	else if (dir == 3) {
		for (int r = cctv.r + 1; r < N; r++) {
			if (map[r][cctv.c] == 6) break;
			map[r][cctv.c] = -1;
		}
	}
}

void DFS(int cctv_idx) {
	if (cctv_idx == cctv_size) {
		int cnt = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (map[r][c] == 0) {
					cnt++;
				}
			}
		}
		if (ans > cnt) {
			ans = cnt;
		}
		return;
	}

	int backup[8][8];
	int type = cctv[cctv_idx].type;

	for (int dir = 0; dir < rotation[type]; dir++) {
		map_cpy(backup, map);
		if (type == 1) {
			update(dir, cctv[cctv_idx]);
		}
		else if (type == 2) {
			update(dir, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
		}
		else if (type == 3) {
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
		}
		else if (type == 4) {
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
		}
		else if (type == 5) {
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
			update(dir + 3, cctv[cctv_idx]);
		}

		DFS(cctv_idx + 1);

		map_cpy(map, backup);
	}
}

int main() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
			if (map[r][c] != 0 && map[r][c] != 6) {
				cctv[cctv_size].r = r;
				cctv[cctv_size].c = c;
				cctv[cctv_size].type = map[r][c];
				cctv_size++;
			}
		}
	}
	DFS(0);
	cout << ans << endl;
	return 0;
}