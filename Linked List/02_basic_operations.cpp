/**
 *    author: A K M S Limon
 *    created: 05-March-2026  02:05:17
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = NULL;
  }
};

void printLinklist(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << "Temp: " << temp << '\n';
    cout << "Temp->data: " << temp->data << '\n';
    cout << "Temp->next: " << temp->next << '\n';
    temp = temp->next;
  }
}

Node* insertAtHead(Node* head, int value) {
  Node* newNode = new Node(value);
  newNode->next = head;
  return newNode;
}

Node* insertAtEnd() {
  
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  head->next = second;
  second->next = third;

  printLinklist(head);

  return 0;
}