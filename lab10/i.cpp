#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n + 1);
  vector<int> d(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    d[v]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) q.push(i);
  }
  vector<int> ans;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);
    for (int v : a[u]) {
      d[v]--;
      if (d[v] == 0) q.push(v);
    }
  }
  if (ans.size() != n) {
    cout << "Impossible\n";
  } else {
    cout << "Possible\n";
    for (int& x : ans) cout << x << " ";
  }
}