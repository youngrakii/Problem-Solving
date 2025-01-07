#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int N;
ll answer;
vector<pii> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    v.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        pii p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }

    for (int i = N - 2; i >= 0; --i)
    {
        answer += (ll)v[i].first * v[i].second * v[N - 1].second;
    }

    cout << answer;
    return 0;
}