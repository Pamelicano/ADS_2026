// Input 1
// 7 6
// 4 3
// both 2 7 4
// both 1 7 2
// big 4 6 1
// big 3 7 3
// small 5 6 1
// both 5 7 10

// output: 67

#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5;
int par[N], sz[N];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

bool unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return false;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  cin >> x >> y;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  vector<tuple<int, int, int>> e;
  for (int i = 0; i < m; i++) {
    string cmd;
    cin >> cmd;
    int u, v, c;
    cin >> u >> v >> c;
    int cost;
    if (cmd == "both")
      cost = c * min(x, y);
    else if (cmd == "big")
      cost = c * x;
    else
      cost = c * y;
    e.push_back({cost, u, v});
  }
  sort(e.begin(), e.end());
  int ans = 0;
  int tt = 0;
  for (auto& [w, u, v] : e) {
    if (unite(u, v)) {
      ans += w;
      tt++;
    }
  }
  if (tt == n - 1)
    cout << ans;
  else
    cout << -1;
}