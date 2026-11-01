#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *l, *r;

  Node(int x) : val(x), l(nullptr), r(nullptr) {}
};

struct BST {
  Node* root = nullptr;

  Node* insert(Node* t, int x) {
    if (!t) return new Node(x);
    if (x <= t->val) {
      t->l = insert(t->l, x);
    } else
      t->r = insert(t->r, x);
    return t;
  }

  void inorder(Node* t) {
    if (!t) return;
    cout << t->val << " ";
    inorder(t->l);
    inorder(t->r);
  }
};

int main() {
  BST t;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    t.root = t.insert(t.root, x);
  }
  t.inorder(t.root);
}