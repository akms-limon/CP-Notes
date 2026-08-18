/**
 *    author: A K M S Limon
 *    created: 08-June-2026  15:38:34
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 10;
vector<vector<int>> g(N);
int par[N];

void dfs(int u, int p) {
  par[u] = p;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

vector<int> path(int u) {
  vector<int> ans;
  while (u != -1) {
    ans.push_back(u);
    u = par[u];
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int32_t main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1);
  int x, y; cin >> x >> y;
  vector<int> path_x = path(x);
  vector<int> path_y = path(y);
  int lca = -1;
  for (int i = 0; i < min(path_x.size(), path_y.size()); i++) {
    if (path_x[i] == path_y[i]) {
      lca = path_x[i];
    }
    else {
      break;
    }
  }
  cout << "LCA : " << lca << '\n';
  return 0;
}