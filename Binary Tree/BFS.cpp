/**
 *    author: A K M S Limon
 *    created: 02-May-2026  22:28:26
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

vector<vector<int>> bfs(TreeNode *root) {
  vector<vector<int>> ans;
  if (root == NULL) return ans;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left != NULL) q.push(node->left);
      if (node->left != NULL) q.push(node->right);
      level.push_back(node->data);
    }
    ans.push_back(level);
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  bfs(root);
  return 0;
}