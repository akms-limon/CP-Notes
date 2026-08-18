/**
 *    author: A K M S Limon
 *    created: 11-May-2024  11:47:56
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;
vector<int> g[N];
int col[N];
bool cycle;

void dfs(int u) {
    col[u] = 1;
    for (auto v : g[u]) {
        if (col[v] == 0) dfs(v);
        else if (col[v] == 1) {
            cycle = true;
        }
    }
    col[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (col[i] == 0) dfs(i);
    }
    cout << (cycle ? "YES\n" : "NO\n") << '\n';
    return 0;
}