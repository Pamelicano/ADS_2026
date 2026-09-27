#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  ll x = 0, y = 0;
  vector<ll> a(n, 0);
  for (int i = 0; i < n; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[i] = max(x2 - x, y2 - y);
  }
  sort(all(a));
  cout << a[k - 1] << "\n";
}