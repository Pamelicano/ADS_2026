#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define ll long long

bool solve(vector<int>& a, int h, int k, int all) {
  int tt = 0;
  for (int i = 0; i < a.size(); i++) {
    tt = tt + (a[i] + k - 1) / k;
  }
  return tt <= h;
}

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  int all = 0;
  for (int& x : a) {
    cin >> x;
    all += x;
  }
  sort(all(a));
  int l = 1, r = 1e9 + 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (solve(a, h, mid, all)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << "\n";
  return 0;
}