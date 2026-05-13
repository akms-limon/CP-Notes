/**
 *    author: A K M S Limon
 *    created: 05-March-2026  01:57:33
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  int data;
  Node* next;

  Node() {
    data = 0;
    next = NULL;
  }
  
  Node(int value) {
    data = value;
    next = NULL;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);

  head->next = second;
  second->next = third;
  return 0;
}