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

  int mx_sum() {
    Node* cur = front;
    int cur_sum = front->val;
    int mx = front->val;
    cur = cur->next;
    while (cur != nullptr) {
      cur_sum = max(cur->val, cur_sum + cur->val);
      mx = max(mx, cur_sum);
      cur = cur->next;
    }
    return mx;
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
  int ans = ll->mx_sum();
  cout << ans << "\n";
  return 0;
}