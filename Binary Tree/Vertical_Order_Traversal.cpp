/**
 *    author: A K M S Limon
 *    created: 06-May-2026  02:20:13
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode (int val) {
    data = val;
    left = right = nullptr;
  }
};

map<int, map<int, multiset<int>>> vertical_order_traversal(TreeNode* root) {
  map<int, map<int, multiset<int>>> mp;
  int level = 0, v_level = 0;
  queue<pair<TreeNode*, int>> q;
  q.push({root, v_level});
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      pair<TreeNode*, int> x = q.front();
      q.pop();
      mp[x.second][level].insert(x.first->data);
      if (x.first->left != NULL) q.push({x.first->left, x.second - 1});
      if (x.first->right != NULL) q.push({x.first->right, x.second + 1});
    }
    level++;
  }
  return mp;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  map<int, map<int, multiset<int>>> ans;

  ans = vertical_order_traversal(root);

  for (auto it : ans) {
    for (auto p : it.second) {
      for (auto x : p.second) {
        cout << x << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}