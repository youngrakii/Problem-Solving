#include <iostream>
#include <vector>
using namespace std;
vector<int> connection[1002];
vector<bool> vis(1002, false);
void dfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < connection[v].size(); i++) {
        int to = connection[v][i];
        if (!vis[to]) {
            dfs(to);
        }
    }
}
int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            connection[i].clear();
            vis[i] = false;
            int v;
            cin >> v;
            connection[i].push_back(v);
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i);
            }
        }
        cout << count << "\n";
        }
    return 0;
}