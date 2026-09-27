#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()

int bin_search(vector<int>& a, int l, int r) {
  return int(upper_bound(all(a), r) - lower_bound(all(a), l));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  sort(all(a));
  while (q--) {
    int l1, r1;
    cin >> l1 >> r1;
    int l2, r2;
    cin >> l2 >> r2;
    int ans = bin_search(a, l1, r1) + bin_search(a, l2, r2);
    int left = max(l1, l2);
    int right = min(r1, r2);
    if (left <= right) ans -= bin_search(a, left, right);
    cout << ans << "\n";
  }
}