#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2 * 1e5;
int par[N];

int find(int x) {
  if (par[x] == x) {
    return x;
  }
  return par[x] = find(par[x]);
}

int main() {
  ll n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> g(m);
  for (int i = 0; i < m; i++) {
    cin >> g[i].second.first >> g[i].second.second >> g[i].first;
  }
  // for (pair<int, pair<int, int>> x : g)
  //   cout << x.second.first << " " << x.second.second << " " << x.first <<
  //   "\n";
  sort(g.begin(), g.end());
  for (int i = 1; i <= n; i++) par[i] = i;
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    int l = g[i].second.first;
    int r = g[i].second.second;
    int c = g[i].first;
    int p = find(l);
    while (p < r) {
      ans += c;
      par[p] = find(p + 1);
      p = find(p);
    }
  }
  cout << ans;
}