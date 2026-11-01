#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (a[mid] == t) {
        ans = 1;
        break;
      }
      if (mid > t) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}