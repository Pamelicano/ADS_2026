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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    par[i] = i;
    sz[i] = 1;
  }
  int mn = min_element(a.begin() + 1, a.end()) - a.begin();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i != mn and unite(mn, i)) ans += (a[mn] + a[i]);
  }
  cout << ans;
}