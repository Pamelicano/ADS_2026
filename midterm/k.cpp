#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  int m;
  cin >> m;
  vector<int> b(m);
  for (int& x : b) cin >> x;
  vector<int> c(n + m);
  int i = 0, j = 0, k = 0;
  while (i < n and j < m) {
    if (a[i] <= b[j]) {
      c[k++] = a[i++];
    } else
      c[k++] = b[j++];
  }
  while (i < n) c[k++] = a[i++];
  while (j < m) c[k++] = b[j++];
  for (int& x : c) cout << x << " ";
}