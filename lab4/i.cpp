#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *l, *r;
  Node(int x) : val(x), l(nullptr), r(nullptr) {}
};

struct BST {
  Node* root = NULL;

  Node* insert(Node* t, int x) {
    if (!t) return new Node(x);
    if (x <= t->val)
      t->l = insert(t->l, x);
    else
      t->r = insert(t->r, x);
    return t;
  }
  int lf = 0;

  void dfs(Node* t) {
    if (!t) return;

    if (!t->l and !t->r) {
      lf++;
      return;
    }
    dfs(t->l);
    dfs(t->r);
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
  t.dfs(t.root);
  cout << t.lf << "\n";
  return 0;
}