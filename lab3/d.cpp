#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& a, int k) {
  int l = 0, r = a.size();
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] > k)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<int> pref_sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref_sum[i] = pref_sum[i - 1] + a[i - 1];
  }
  int p;
  cin >> p;
  while (p--) {
    int x;
    cin >> x;
    cout << find(a, x) << " ";
    cout << pref_sum[find(a, x)] << "\n";
  }
}