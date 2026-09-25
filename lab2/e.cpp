#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  Node* next;

  Node(int val) {
    this->val = val;
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

  void pop_front() { front = nullptr; }

  void remove_middle(int n) {
    int pos = n / 2;
    if (pos == 0) {
      Node* tmp = front;
      front = front->next;
      delete tmp;
      return;
    }
    Node* cur = front;
    for (int i = 0; i < pos - 1; i++) {
      cur = cur->next;
    }
    Node* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
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
  LinkedList* ll = new LinkedList();
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ll->push_back(x);
  }
  ll->remove_middle(n);
  ll->print();
  return 0;
}