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

int maxSum(TreeNode *root, int &mx) {
  if (root == NULL) {
    return 0;
  }
  int lSum = max(0, maxSum(root->left, mx));
  int rSum = max(0, maxSum(root->right, mx));
  mx = max(mx, lSum + rSum + root->data);
  return root->data + max(lSum, rSum);
}

int maxPathSum (TreeNode *root) {
  int mx = INT_MIN;
  maxSum(root, mx);
  return mx;
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

  cout << maxPathSum(root) << '\n';

  return 0;
}