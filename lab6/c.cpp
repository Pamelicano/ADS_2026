#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& a, int l, int r, int m) {
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++) L[i] = a[l + i];
  for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      a[k++] = L[i++];
    else
      a[k++] = R[j++];
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];
}

void mergesort(vector<int>& a, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, r, m);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& X : a) cin >> X;
  mergesort(a, 0, n - 1);
  int mn = 1e9;
  for (int i = 1; i < n; i++) {
    mn = min(mn, a[i] - a[i - 1]);
  }
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] == mn) {
      cout << a[i - 1] << " " << a[i] << " ";
    }
  }
}