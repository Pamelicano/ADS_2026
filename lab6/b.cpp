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
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;
  mergesort(a, 0, n - 1);
  mergesort(b, 0, m - 1);
  int i = 0, j = 0;
  while (i < n and j < m) {
    if (a[i] == b[j]) {
      cout << a[i] << " ";
      i++;
      j++;
    } else if (a[i] < b[j])
      i++;
    else
      j++;
  }
}