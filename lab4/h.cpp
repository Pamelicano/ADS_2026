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
    if (x <= t->val)
      t->l = insert(t->l, x);
    else
      t->r = insert(t->r, x);
    return t;
  }

  int sm = 0;

  void trans(Node* t) {
    if (!t) return;

    trans(t->r);
    sm += t->val;
    t->val = sm;
    trans(t->l);
  }

    void inorder(Node* t) {
    if (!t) return;
    inorder(t->r);
    cout << t->val << ' ';
    inorder(t->l);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  BST t;
  int n;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;
    t.root = t.insert(t.root, x);
  }

  t.trans(t.root);
  t.inorder(t.root);

  return 0;
}