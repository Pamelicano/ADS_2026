#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *l, *r;
  Node(int x) : val(x), l(NULL), r(NULL) {};
};

struct BST {
  Node* root = nullptr;

  Node* insert(Node* t, int x) {
    if (!t) return new Node(x);
    if (x <= t->val) {
      t->l = insert(t->l, x);
    } else {
      t->r = insert(t->r, x);
    }
    return t;
  }

  int cnt(Node* t) {
    if (!t) return 0;
    int cnts = (t->r && t->l);
    return cnts + cnt(t->r) + cnt(t->l);
  }
};

int main() {
  BST t;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
    t.root = t.insert(t.root, x);
  }
  cout << t.cnt(t.root) << "\n";
}