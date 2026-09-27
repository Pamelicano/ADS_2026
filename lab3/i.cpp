#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define ll long long

bool solve(vector<ll>& a, ll k, ll mx) {
  ll blocks = 1;
  ll cnt = 0;
  for (ll& x : a) {
    if (cnt + x > mx) {
      blocks++;
      cnt = x;
    } else {
      cnt += x;
    }
  }
  return blocks <= k;
}

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll l = 0, r = 0;
  for (ll& x : a) {
    cin >> x;
    l = max(l, x);
    r += x;
  }
  while (l < r) {
    ll mid = l + (r - l) / 2;
    if (solve(a, k, mid)) {
      r = mid;
    } else
      l = mid + 1;
  }
  cout << l << "\n";
}