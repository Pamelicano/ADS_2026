#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  vector<ll> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
  int ans = n;
  for (int l = 0; l < n; l++) {
    int lf = l, ri = n - 1;
    while (lf <= ri) {
      int mid = (lf + ri) / 2;
      if (pref[mid + 1] - pref[l] >= k) {
        ri = mid - 1;
      } else {
        lf = mid + 1;
      }
    }
    if (lf < n) ans = min(ans, lf - l + 1);
  }
  cout << ans << "\n";
}
