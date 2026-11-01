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
  int dfs(Node* t) {
    if (!t) return 0;
    return 1 + max(dfs(t->l), dfs(t->r));
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
  cout << t.dfs(t.root) << "\n";
}