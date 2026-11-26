// Input 1
// 3 0 0 28 0 0 0 28 0 0
// ouput 1
// 0

#include <bits/stdc++.h>

using namespace std;

#define ll long long
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
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  vector<pair<ll, pair<int, int>>> e;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ll w;
      cin >> w;
      if (i < j and w > 0) {
        e.push_back({w, {i, j}});
      }
      if (w == 0) unite(i, j);
    }
  }
  sort(e.begin(), e.end());
  ll ans = 0;
  for (int i = 0; i < e.size(); i++) {
    if (unite(e[i].second.first, e[i].second.second)) ans += e[i].first;
  }
  cout << ans;
}