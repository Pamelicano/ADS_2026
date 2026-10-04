#include <bits/stdc++.h>

using namespace std;

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

  Node* findMin(Node* t) {
    while (t && t->l) t = t->l;
    return t;
  }

  Node* erase(Node* t, int x) {
    if (!t) return NULL;
    if (x < t->val)
      t->l = erase(t->l, x);
    else if (x > t->val)
      t->r = erase(t->r, x);
    else {
      if (!t->l) return t->r;
      if (!t->r) return t->l;
      Node* m = findMin(t->r);
      t->val = m->val;
      t->r = erase(t->r, m->val);
    }
    return t;
  }

  void inorder(Node* t) {
    if (!t) return;
    inorder(t->l);
    cout << t->val << " ";
    inorder(t->r);
  }

  bool check(Node* root, string s) {
    Node* cur = root;
    for (char c : s) {
      if (!cur) return false;
      if (c == 'L')
        cur = cur->l;
      else
        cur = cur->r;
    }
    return cur != NULL;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  BST t;
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int x : a) t.root = t.insert(t.root, x);
  while (m--) {
    string p;
    cin >> p;
    if (t.check(t.root, p))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}