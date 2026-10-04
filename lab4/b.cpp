#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *l, *r;
  Node(int v) : val(v), l(NULL), r(NULL) {}
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

  void inorder(Node* t) {
    if (!t) return;
    inorder(t->l);
    cout << t->val << " ";
    inorder(t->r);
  }

  Node* find(Node* t, int x) {
    if (!t or t->val == x) return t;
    if (x < t->val) return find(t->l, x);
    return find(t->r, x);
  }
  int sz(Node* t) {
    if (!t) return 0;
    return 1 + sz(t->l) + sz(t->r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  BST t;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int x : a) t.root = t.insert(t.root, x);
  int x;
  cin >> x;
  cout << t.sz(t.find(t.root, x)) << "\n";
  return 0;
}