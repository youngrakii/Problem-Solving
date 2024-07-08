#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int N;
vector<int> v;
set<int> res;
bool visit[101];

void dfs(int start, int next, set<int> tmp) {
    if (visit[next]) {
        if (start == next) {
            res.insert(tmp.begin(), tmp.end());
        }
        return;
    }

    visit[next] = true;
    tmp.insert(next);
    
    dfs(start, v[next], tmp);
}

void solution() {
    for (int i = 1; i <= N; i++) {
        visit[i] = true;
        dfs(i, v[i], { i });
        
        memset(visit, false, sizeof(visit));
    }

    cout << res.size() << endl;
    for (auto elem : res) {
        cout << elem << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int a;
    v.push_back(-1);
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    solution();

    return 0;
}