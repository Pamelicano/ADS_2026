// Nugman and Graph 2
// Input 1: 8 7 7 8 3 4 5 6 5 7 5 8 6 7 6 8
// Output 1: 3 2 2 1 1 1 1 0

#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2 * 1e5;
int par[N], sz[N];
bool act[N];
vector<ll> ans;

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  ans.resize(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int comp = 0;
  for (int v = n; v >= 1; v--) {
    ans[v] = comp;
    act[v] = true;
    par[v] = v;
    sz[v] = 1;
    comp++;
    for (int u : g[v]) {
      if (act[u]) {
        if (find(v) != find(u)) {
          unite(v, u);
          comp--;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}