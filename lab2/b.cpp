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

  LinkedList() { front = NULL; }
  void solve() {
    Node* cur = front;
    while (cur != nullptr and cur->next != nullptr) {
      Node* tmp = cur->next;
      cur->next = cur->next->next;
      delete tmp;
      cur = cur->next;
    }
  }
  void print() {
    Node* cur = front;
    while (cur != nullptr) {
      cout << cur->val << " ";
      cur = cur->next;
    }
    cout << "\n";
  }

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
  ll->solve();
  ll->print();
  return 0;
}