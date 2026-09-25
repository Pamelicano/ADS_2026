#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  string val;
  Node *next, *prev;
  Node(string x) {
    this->val = x;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DLL {
 public:
  Node* front;
  Node* back;

  DLL() {
    front = nullptr;
    back = nullptr;
  }

  void add_back(string x) {
    Node* node = new Node(x);
    if (front == nullptr) {
      front = node;
      back = node;
      return;
    }
    node->prev = back;
    back->next = node;
    back = node;
  }

  void add_front(string x) {
    Node* node = new Node(x);
    if (front == nullptr) {
      front = node;
      back = node;
      return;
    }
    node->next = front;
    front->prev = node;
    front = node;
  }
  void erase_back() {
    if (back == nullptr) return;
    Node* tmp = back;
    back = back->prev;
    if (back != nullptr) {
      back->next = nullptr;
    } else
      front = nullptr;
    delete tmp;
  }
  void erase_front() {
    if (front == nullptr) return;
    Node* tmp = front;
    front = front->next;
    if (front != nullptr) {
      front->prev = nullptr;
    } else
      back = nullptr;
    delete tmp;
  }

  void erase() {
    Node* cur = front;
    while (cur != nullptr) {
      Node* tmp = cur;
      cur = cur->next;
      delete tmp;
    }
    front = nullptr;
    back = nullptr;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  DLL* ll = new DLL();
  string s;
  while (getline(cin, s)) {
    if (s == "exit") {
      cout << "goodbye\n";
      break;
    }
    stringstream ss(s);
    string x, y;
    ss >> x >> y;
    if (x == "front") {
      if (ll->front != nullptr) {
        cout << ll->front->val << "\n";
      } else
        cout << "error\n";
    } else if (x == "back") {
      if (ll->back != nullptr) {
        cout << ll->back->val << "\n";
      } else
        cout << "error\n";
    } else if (x == "add_front") {
      ll->add_front(y);
      cout << "ok\n";
    } else if (x == "add_back") {
      ll->add_back(y);
      cout << "ok\n";
    } else if (x == "erase_front") {
      if (ll->front != nullptr) {
        cout << ll->front->val << "\n";
        ll->erase_front();
      } else {
        cout << "error\n";
      }
    } else if (x == "erase_back") {
      if (ll->back != nullptr) {
        cout << ll->back->val << "\n";
        ll->erase_back();
      } else
        cout << "error\n";
    } else if (x == "clear") {
      ll->erase();
      cout << "ok\n";
    }
  }
  return 0;
}