#include <bits/stdc++.h>

using namespace std;
#define all(v) a.begin(), a.end()
#define ll long long

ll solve(vector<ll>& a, int l, int r) {
  int left = 0, right = a.size();
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (a[mid] < l) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  ll left2 = 0, right2 = a.size();
  while (left2 < right2) {
    ll mid2 = left2 + (right2 - left2) / 2;
    if (a[mid2] > r) {
      right2 = mid2;
    } else {
      left2 = mid2 + 1;
    }
  }
  //   cout << left << " " << left2 << "\n";
  return left2 - left;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (ll& x : a) cin >> x;
  sort(all(a));
  while (q--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    long long ans = solve(a, l1, r1) + solve(a, l2, r2);
    if (max(l1, l2) <= min(r1, r2)) {
      ans -= solve(a, max(l1, l2), min(r1, r2));
    }
    cout << ans << "\n";
  }
}