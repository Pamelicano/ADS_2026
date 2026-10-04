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
    if (x == t->val) return t;
    if (x < t->val) {
      t->l = insert(t->l, x);
    } else
      t->r = insert(t->r, x);
    return t;
  }
  int cnt = 0;
  int ans = -1;
  void inorder(Node* t, int k) {
    if (!t or cnt >= k) return;
    inorder(t->l, k);
    cnt++;
    if (cnt == k) {
      cout << t->val;
      return;
    }
    inorder(t->r, k);
  }
};

int main() {
  BST t;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    t.root = t.insert(t.root, x);
  }
  if (k > n) {
    cout << "-1\n";
    return 0;
  }
  t.inorder(t.root, k);

  return 0;
}