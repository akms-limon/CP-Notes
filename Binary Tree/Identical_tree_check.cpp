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

bool isIdentical (TreeNode *p, TreeNode* q) {
  if (p == NULL || q == NULL) {
    return (p == q);
  }
  return (p->data == q->data)
  && isIdentical(p->left, q->left)
  && isIdentical(p->right, q->right);
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  struct TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->right = new TreeNode(5);

  cout << isIdentical(root, root1) << '\n';

  return 0;
}