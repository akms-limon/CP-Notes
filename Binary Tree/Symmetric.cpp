/**
 *    author: A K M S Limon
 *    created: 15-May-2026  01:31:21
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

bool Symmetric(TreeNode* root) {
  if (root == nullptr) return true;
  queue<TreeNode*> q;
  q.push(root->left);
  q.push(root->right);
  while (!q.empty()) {
    TreeNode* x = q.front();
    q.pop();
    TreeNode* y = q.front();
    q.pop();
    if (x == NULL && y == NULL) continue;
    if (x == NULL || y == NULL) return false;
    if (x->data != y->data) return false;
    q.push(x->left);
    q.push(y->right);
    q.push(x->right);
    q.push(y->left);
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  return 0;
}