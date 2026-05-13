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

void preOrder(TreeNode *root) {
  if (root == nullptr) return;
  cout << root->data << ' ';
  preOrder(root->left);
  preOrder(root->right);
}

vector<int> preOrderIterator(TreeNode *root) {
  stack<TreeNode*> st;
  vector<int> ans;
  st.push(root);
  while (!st.empty()) {
    root = st.top();
    st.pop();
    ans.push_back(root->data);
    if (root->right != NULL) st.push(root->right);
    if (root->left != NULL) st.push(root->left);
  }
  return ans;
}

void inOrder(TreeNode *root) {
  if (root == nullptr) return;
  inOrder(root->left);
  cout << root->data << ' ';
  inOrder(root->right);
}

vector<int> inOrderIterator(TreeNode *root) {
  stack<TreeNode*> st;
  vector<int> ans;
  st.push(root);
  while(!st.empty()) {
    if (root != NULL) {
      st.push(root);
      root = root->left;
    }
    else {
      if (st.empty()) break;
      root = st.top();
      ans.push_back(root->data);
      root = root->right;
    }
  }
  return ans;
}

void postOrder(TreeNode *root) {
  if (root == nullptr) return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << ' ';
}

vector<int> postOrderUsingTwoStack(TreeNode *root) {
  stack<TreeNode*> st1, st2;
  st1.push(root);
  while(!st1.empty()) {
    root = st1.top();
    st1.pop();
    if (root->left != NULL) st1.push(root->left);
    if (root->right != NULL) st1.push(root->right);
    st2.push(root);
  }
  vector<int> ans;
  while (!st2.empty()) {
    ans.push_back(st2.top()->data);
    st2.pop();
  }
  return ans;
}

void preInPostTraversal(TreeNode* root) {
  stack<pair<TreeNode*, int>> st;
  st.push({root, 1});
  vector<int> pre, in, post;
  if(root == NULL) return;
  while (!st.empty()) {
    auto it = st.top();
    st.pop();
    if (it.second == 1) {
      pre.push_back(it.first->data);
      it.second++;
      st.push(it);
      if (it.first->left != NULL) {
        st.push({it.first->left, 1});
      }
    }
    else if (it.second == 2) {
      in.push_back(it.first->data);
      it.second++;
      st.push(it);
      if (it.first->right != NULL) {
        st.push({it.first->right, 1});
      }
    }
    else {
      post.push_back(it.first->data);
    }
  }
  // now print the pre in and post vector to print the travarsals.............
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  struct TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);

  preOrder(root);
  return 0;
}