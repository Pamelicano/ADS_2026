#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  int k;
  cin >> k;
  int ans = -200001;
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (a[mid] > k) {
      r = mid - 1;
    } else {
      l = mid + 1;
      ans = a[mid];
    }
  }
  if (ans != k)
    cout << "No\n";
  else
    cout << "Yes\n";
}