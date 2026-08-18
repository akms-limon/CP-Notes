/**
 *    author: A K M S Limon
 *    created: 07-June-2026  12:30:17
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

/* Given Q Queries, Q <= 10^5
  In each query given node V,
  Print subtree sumf of V and Number of ever numbers
  in subtree of V
*/

const int N = 1e5 + 10;
vector<vector<int>> g(N);
int subtree_sum[N], even_cnt[N];

void dfs(int u, int par) {
  if (u % 2 == 0) {
    even_cnt[u]++;
  }
  subtree_sum[u] = u;
  for (auto v : g[u]) {
    if (v != par) {
      dfs(v, u);
      subtree_sum[u] += subtree_sum[v];
      even_cnt[u] += even_cnt[v];
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
  dfs(root, -1);
  int q; cin >> q;
  while (q--) {
    int node; cin >> node;
    cout << "subtree sum : " << subtree_sum[node] << ' ' << "Even count : " << even_cnt[node] << '\n';
  }
  return 0;
}