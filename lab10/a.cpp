#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j];
  }
  queue<pair<int, pair<int, int>>> q;
  int tt = 0, time = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 2) {
        q.push({0, {i, j}});
      } else if (a[i][j] == 1)
        tt++;
    }
  }
  if (tt == 0) {
    cout << 0;
    return 0;
  }
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    int t = cur.first;
    int x = cur.second.first, y = cur.second.second;
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx >= 0 and nx < n and ny >= 0 and ny < m and a[nx][ny] == 1) {
        a[nx][ny] = 2;
        tt--;
        q.push({t + 1, {nx, ny}});
        time = max(time, t + 1);
      }
    }
  }
  if (tt == 0) {
    cout << time;
  } else
    cout << -1;
  return 0;
}