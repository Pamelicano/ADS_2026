#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll l = 1, r = min(n, (ll)1000000001);
    while (l < r) {
      ll mid = l + (r - l + 1) / 2;
      if (mid <= n / mid) {
        l = mid;
      } else
        r = mid - 1;
    }
    cout << l << " ";
  }
}