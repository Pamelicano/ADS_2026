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

  int dim = 0;

  int height(Node* t) {
    if (!t) return 0;

    int L = height(t->l);
    int R = height(t->r);

    dim = max(dim, L + R);
    return 1 + max(L, R);
  }
};

int main() {
  BST t;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    t.root = t.insert(t.root, x);
  }
  t.height(t.root);
  cout << t.dim + 1 << "\n";
  return 0;
}