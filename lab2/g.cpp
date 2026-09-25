#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  string val;
  Node* next;

  Node(string x) {
    this->val = x;
    this->next = nullptr;
  }
};

class LinkedList {
 public:
  Node* front;

  LinkedList() { front = nullptr; }

  void push_back(string x) {
    Node* node = new Node(x);
    if (front == nullptr) {
      front = node;
      return;
    }
    Node* cur = front;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = node;
  }

  Node* shift_k(Node* head, int n, int k) {
    if (head == nullptr or head->next == nullptr) {
      return head;
    }
    k %= n;
    if (k == 0) {
      return head;
    }
    Node* cur = head;
    for (int i = 0; i < k - 1; i++) cur = cur->next;
    Node* newhead = cur->next;
    Node* tail = newhead;
    while (tail->next != nullptr) {
      tail = tail->next;
    }
    tail->next = head;
    cur->next = nullptr;
    return newhead;
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
  int n, k;
  cin >> n >> k;
  LinkedList* ll = new LinkedList();
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    ll->push_back(x);
  }
  LinkedList* ll2 = new LinkedList();
  ll2->front = ll2->shift_k(ll->front, n, k);
  ll2->print();
  return 0;
}