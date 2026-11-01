#include <bits/stdc++.h>

using namespace std;

bool heapify(vector<int>& a, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int m = i;
  if (l < n and a[m] > a[l]) m = l;
  if (r < n and a[m] > a[r]) m = r;
  if (m != i) {
    return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  for (int i = 0; i < n; i++) {
    if (!heapify(a, n, i)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}