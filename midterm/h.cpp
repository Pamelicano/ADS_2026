#include <bits/stdc++.h>

using namespace std;
#define psi pair<string, int>

void merge(vector<psi>& a, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<psi> L(n1), R(n2);
  for (int i = 0; i < n1; i++) L[i] = a[i + l];
  for (int i = 0; i < n2; i++) R[i] = a[i + m + 1];

  int i = 0, j = 0, k = l;
  while (i < n1 and j < n2) {
    if (L[i].second <= R[j].second) {
      a[k++] = L[i++];
    } else
      a[k++] = R[j++];
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];
}

void mergesort(vector<psi>& a, int l, int r) {
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
  vector<psi> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  mergesort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << a[i].first << "\n";
  }
}