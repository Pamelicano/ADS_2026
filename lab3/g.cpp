#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define ll long long

bool solve(vector<int>& a, double mid, int k) {
  ll cnt = 0;
  for (int& x : a) {
    cnt += (ll)(x / mid);
    if (cnt >= k) return true;
  }
  return cnt >= k;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  sort(all(a));
  double l = (double)0, r = *max_element(all(a));
  int it = 100;
  while (it--) {
    double mid = (l + r) / 2;
    if (solve(a, mid, k)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(10) << l << '\n';
}
