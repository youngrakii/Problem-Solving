#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#define mod 1000000007

using namespace std;

typedef long long ll;
const int INF = INT_MAX;
const int MAX_N = 20000000 + 5;

int N, M, X, Y;
bool Error[MAX_N];
vector<int> Error_num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int MAX_gap = 0;

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        Error[a] = true;
        Error_num.push_back(a);
        if (!i)
            MAX_gap = max(a - 1, MAX_gap);
        else
            MAX_gap = max(MAX_gap, a - (Error_num[i - 1] + 1));
        if (i == M - 1) {
            MAX_gap = max(MAX_gap, N - a);
        }
    }

    cin >> X >> Y;
    if (MAX_gap >= X) {
        cout << M - Y << "\n";
        return 0;
    }

    int cnt = 0;
    for (int j = 1; j < 1 + X; j++) {
        if (Error[j])
            cnt++;
    }

    int Min_Error = cnt;
    for (int i = 2; i <= N - X + 1; i++) {
        if (Error[i - 1])
            cnt--;
        if (Error[i + X - 1])
            cnt++;
        Min_Error = min(cnt, Min_Error);
        if (Min_Error < Y)
            break;
    }

    if (Min_Error < Y)
        cout << M - Y << "\n";
    else
        cout << M - Min_Error << "\n";

    return 0;
}
