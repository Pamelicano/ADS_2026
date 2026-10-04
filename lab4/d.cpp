#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct Node {
  int val;
  Node *l, *r;
  Node(int x) : val(x), l(NULL), r(NULL) {};
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

  queue<Node*> q;
  q.push(t.root);

  vector<ll> sm;
  while (!q.empty()) {
    int sz = q.size();
    ll ans = 0;
    for (int i = 0; i < sz; i++) {
      Node* cur = q.front();
      q.pop();
      ans += cur->val;
      if (cur->l) q.push(cur->l);
      if (cur->r) q.push(cur->r);
    }
    sm.push_back(ans);
  }
  cout << sm.size() << "\n";
  for (ll& x : sm) cout << x << " ";
  return 0;
}