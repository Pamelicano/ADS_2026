#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll ans = 0;

void merge(vector<int>& a, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++) L[i] = a[l + i];
  for (int i = 0; i < n2; i++) R[i] = a[m + i + 1];
  int i = 0, j = 0, k = l;
  while (i < n1 and j < n2) {
    if (L[i] <= R[j]) {
      a[k++] = L[i++];
    } else {
      ans += n1 - i;
      a[k++] = R[j++];
    }
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];
}

void mergesort(vector<int>& a, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  mergesort(a, 0, n - 1);
  cout << ans << "\n";
}