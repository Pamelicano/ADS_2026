#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *l, *r;
  Node(int x) : val(x), l(NULL), r(NULL) {}
};

struct BST {
  Node* root = NULL;

  Node* insert(Node* t, int x) {
    if (!t) return new Node(x);
    if (x <= t->val) {
      t->l = insert(t->l, x);
    } else {
      t->r = insert(t->r, x);
    }
    return t;
  }

  Node* find(Node* t, int x) {
    if (!t or t->val == x) return t;
    if (x < t->val) return find(t->l, x);
    return find(t->r, x);
  }

  void collect(Node* t, vector<int>& res) {
    if (!t) return;
    res.push_back(t->val);
    collect(t->l, res);
    collect(t->r, res);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  BST t;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  for (int x : a) t.root = t.insert(t.root, x);
  int x;
  cin >> x;
  Node* f = t.find(t.root, x);
  vector<int> ans;
  t.collect(f, ans);
  for (int& x : ans) cout << x << " ";
  cout << "\n";
  return 0;
}