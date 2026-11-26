#include <bits/stdc++.h>

using namespace std;

int BFS(int s, const vector<vector<int>>& a, const vector<bool>& r, int n) {
  vector<int> dist(n + 1, -1);
  queue<int> q;

  q.push(s);
  dist[s] = 0;

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (r[v]) {
      return dist[v];
    }
    for (int u : a[v]) {
      if (dist[u] == -1) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
  return -1;
}

void solve(int n, vector<vector<int>>& a, int q) {
  vector<bool> r(n + 1, false);

  while (q--) {
    int t, v;
    cin >> t >> v;

    if (t == 1) {
      r[v] = true;
    } else {
      cout << BFS(v, a, r, n) << '\n';
    }
  }
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  solve(n, a, q);
  return 0;
}
