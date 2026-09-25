#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node(int x) {
    this->val = x;
    this->next = nullptr;
  }
};

class LinkedList {
 public:
  Node* front;
  LinkedList() { front = nullptr; }

  void push_back(int x) {
    Node* node = new Node(x);
    if (front == nullptr) {
      front = node;
      return;
    }
    Node* cur = front;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = node;
  }

  Node* merge(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    Node* head;

    if (a->val <= b->val) {
      head = a;
      a = a->next;
    } else {
      head = b;
      b = b->next;
    }

    Node* cur = head;
    while (a != nullptr and b != nullptr) {
      if (a->val <= b->val) {
        cur->next = a;
        a = a->next;
      } else {
        cur->next = b;
        b = b->next;
      }
      cur = cur->next;
    }
    if (a != nullptr) {
      cur->next = a;
    } else
      cur->next = b;
    return head;
  }

  void print() {
    Node* cur = front;
    while (cur != nullptr) {
      cout << cur->val << " ";
      cur = cur->next;
    }
  }
};

int main() {
  int n;
  cin >> n;
  LinkedList* ll1 = new LinkedList();
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ll1->push_back(x);
  }
  int m;
  cin >> m;
  LinkedList* ll2 = new LinkedList();
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    ll2->push_back(x);
  }
  LinkedList* ll3 = new LinkedList();
  ll3->front = ll3->merge(ll1->front, ll2->front);
  ll3->print();
  return 0;
}