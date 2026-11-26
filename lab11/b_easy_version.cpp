#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 1; i < n; i++) ans += (a[0] + a[i]);
  cout << ans;
}