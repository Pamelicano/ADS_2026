#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>>& a, vector<bool>& visited) {
  visited[v] = true;
  for (int u : a[v]) {
    if (!visited[u]) {
      dfs(u, a, visited);
    }
  }
}

bool comp(int u, int v, vector<vector<int>>& a, int n) {
  vector<bool> visited(n + 1, false);
  dfs(u, a, visited);
  return visited[v];
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  int s, f;
  cin >> s >> f;
  s--;
  f--;
  if (comp(s, f, a, n))
    cout << "YES";
  else
    cout << "NO";
}