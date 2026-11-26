#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(vector<string>& a, int x, int y) {
  int n = a.size();
  int m = a[0].size();
  a[x][y] = '0';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '1') {
      dfs(a, nx, ny);
    }
  }
}

int solve(vector<string>& a) {
  if (a.empty()) return 0;

  int n = a.size();
  int m = a[0].size();
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        ans++;
        dfs(a, i, j);
      }
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (string& x : a) cin >> x;
  cout << solve(a);
  return 0;
}