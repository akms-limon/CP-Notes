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

bool isLeaf (TreeNode *root) {
  return (root->right == NULL && root->left == NULL);
}

void leftSide (TreeNode *root, vector<int> &res) {
  while (root) {
    if (!isLeaf(root)) res.push_back(root->data);
    if (root->left) root = root->left;
    else root = root->right;
  }
}

void rightSide (TreeNode *root, vector<int> &res) {
  vector<int> temp;
  while (root) {
    if (!isLeaf(root)) temp.push_back(root->data);
    if (root->right) root = root->right;
    else root = root->left;
  }
  for (int i = temp.size() - 1; i >= 0; i--) {
    res.push_back(temp[i]);
  }
}

void addLeaves (TreeNode *root, vector<int> &res) {
  if (root == NULL) return;
  if (isLeaf(root)) res.push_back(root->data);
  addLeaves(root->left, res);
  addLeaves(root->right, res);
}

vector<int> boundaryTraversal(TreeNode *root) {
  vector<int> res;
  if (root == NULL) return res;
  if (!isLeaf(root)) res.push_back(root->data);
  leftSide(root->left, res);
  addLeaves(root, res);
  rightSide(root->right, res);
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  vector<int> ans;
  ans = boundaryTraversal(root);
  return 0;
}