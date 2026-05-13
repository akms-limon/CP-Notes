/**
 *    author: A K M S Limon
 *    created: 05-May-2026  23:20:00
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool flag = 1;

struct TreeNode {
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
  TreeNode (int val) {
    data = val;
    left = right = nullptr;
  }
};

int dfs (TreeNode* root) {
  if (root == NULL) return 0;
  int l = dfs(root->left);
  int r = dfs(root->right);
  if (l - r > 1) flag = 0;
  return max(l, r) + 1;
}

bool isBalanced (TreeNode *root) {
  dfs(root);
  return flag;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  return 0;
}