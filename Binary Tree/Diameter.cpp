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

int height(TreeNode *root, int diameter) {
  if (root == NULL) return 0;
  int lh = height(root->left, diameter);
  int rh = height(root->left, diameter);
  diameter = max(diameter, lh + rh);
  return 1 + max(lh, rh);
  return diameter;
}

int diameterOfBinaryTree(TreeNode* root) {
  int diameter = 0;
  height(root, diameter);
  return diameter;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  cout << diameterOfBinaryTree(root) << '\n';

  return 0;
}