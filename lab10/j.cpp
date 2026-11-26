#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis, p, sz;

void dfs(int u, int par) {
  vis[u] = 1;
  p[u] = par;

  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
    sz[u]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  vis.assign(n + 1, 0);
  p.assign(n + 1, -1);
  sz.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vector<int> comp;
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    int root = i;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      comp.push_back(u);
      root = min(root, u);
      for (int v : g[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
    dfs(root, -1);
    for (int u : comp) {
      if (u == root || sz[u] > sz[p[u]]) {
        ans++;
      }
    }
  }

  cout << ans << '\n';
}
