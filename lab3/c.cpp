#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& a, int k) {
  int l = 0, r = a.size();
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] < k)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  vector<int> prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
  }
  while (m--) {
    int x;
    cin >> x;
    cout << find(prefix_sum, x) << "\n";
  }
}