#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
  int s, f;
  cin >> s >> f;
  s--;
  f--;
  vector<int> dist(n, -1);
  queue<int> q;
  q.push(s);
  dist[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == f) {
      cout << dist[v];
      return 0;
    }
    for (int u = 0; u < n; u++) {
      if (a[v][u] == 1 and dist[u] == -1) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
  cout << dist[f];
  return 0;
}