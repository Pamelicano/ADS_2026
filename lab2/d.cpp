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

  void push_front(int x) {
    Node* node = new Node(x);
    if (front == nullptr) {
      front = node;
      return;
    }
    node->next = front;
    front = node;
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
  while (n--) {
    int x;
    cin >> x;
    ll->push_front(x);
  }
  ll->print();
  return 0;
}
