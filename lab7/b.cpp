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
  vector<int> tt(n + m);
  int i = 0, j = 0, k = 0;
  while (i < n and j < m) {
    if (a[i] < b[j]) {
      tt[k] = a[i];
      i++;
      k++;
    } else {
      tt[k] = b[j];
      j++;
      k++;
    }
  }

  while (i < n) tt[k++] = a[i++];
  while (j < m) tt[k++] = b[j++];
  for (int& x : tt) cout << x << " ";
}