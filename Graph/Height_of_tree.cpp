/**
 *    author: A K M S Limon
 *    created: 07-June-2026  12:04:52
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
vector<vector<int>> g(N);
int height[N];

void dfs(int u, int p) {
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      height[u] = max(height[u], height[v] + 1);
    }
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int root = 1;
  dfs(root, 0);
  for (int i = 1; i <= n; i++) {
    cout << height[i] << ' ';
  }
  cout << '\n';
  return 0;
}