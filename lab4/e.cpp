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
  int wight() {
    if (!root) return 0;
    queue<Node*> q;
    q.push(root);

    int mx = 0;
    while (!q.empty()) {
      int sz = q.size();
      mx = max(mx, sz);
      for (int i = 0; i < sz; i++) {
        Node* cur = q.front();
        q.pop();
        if (cur->l) q.push(cur->l);
        if (cur->r) q.push(cur->r);
      }
    }
    return mx;
  }
};

int main() {
  BST t;
  int n;
  cin >> n;
  vector<Node*> ns(n + 1);
  for (int i = 1; i <= n; i++) {
    ns[i] = new Node(i);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    if (c == 0)
      ns[u]->l = ns[v];
    else
      ns[u]->r = ns[v];
  }
  t.root = ns[1];
  cout << t.wight() << "\n";
  return 0;
}