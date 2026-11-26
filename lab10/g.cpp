#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> c, p, pe, cyc;
bool f = false;
void dfs(int u) {
  c[u] = 1;
  for (auto [v, id] : g[u]) {
    if (f) return;
    if (!c[v]) {
      p[v] = u;
      pe[v] = id;
      dfs(v);
    } else if (c[v] == 1) {
      cyc.push_back(id);
      int x = u;
      while (x != v) {
        cyc.push_back(pe[x]);
        x = p[x];
      }
      f = true;
      return;
    }
  }
  c[u] = 2;
}

bool check(int rem) {
  vector<int> d(n + 1, 0);
  for (int u = 1; u <= n; u++)
    for (auto [v, id] : g[u])
      if (id != rem) d[v]++;
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!d[i]) q.push(i);
  int cnt = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cnt++;
    for (auto [v, id] : g[u]) {
      if (id == rem) continue;
      if (--d[v] == 0) q.push(v);
    }
  }
  return cnt == n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  g.resize(n + 1);
  c.assign(n + 1, 0);
  p.assign(n + 1, -1);
  pe.assign(n + 1, -1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
  }
  for (int i = 1; i <= n && !f; i++)
    if (!c[i]) dfs(i);
  if (!f) {
    cout << "YES\n";
    return 0;
  }
  for (int id : cyc) {
    if (check(id)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}
