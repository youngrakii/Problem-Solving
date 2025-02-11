#include <iostream>
#include <algorithm>
#include <cstring> //memset

using namespace std;
const int MAX = 100000;
const int INF = 987654321;


int N;

int graph[MAX][3];

long long cache[MAX][3];



long long minCost(int idx1, int idx2){

    //기저 사례: 범위 초과할 경우

    if (idx1 >= N || idx2 < 0 || idx2>2) return INF;

    //도착점에 도착했을 경우

    if (idx1 == N - 1 && idx2 == 1) return graph[idx1][idx2];

    long long& result = cache[idx1][idx2];

    if (result != -1) return result;
    //총 네 방향으로 갈 수 있다: 오른쪽, 왼쪽 아래, 아래, 오른쪽 아래
    result = graph[idx1][idx2] + min(minCost(idx1, idx2 + 1), min(minCost(idx1 + 1, idx2 - 1), min(minCost(idx1 + 1, idx2), minCost(idx1 + 1, idx2 + 1))));

    return result;

}



int main(void) {
    int K = 1;
    while (1) {
        cin >> N;
        if (N == 0) break;
        memset(cache, -1, sizeof(cache));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> graph[i][j];
            }
        }
        cout << K++ <<". "<< minCost(0, 1) << endl;

    }

    return 0;

}
