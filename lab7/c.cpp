#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct created {
  vector<int> x;
  ll sm;

  created(int m) : x(m), sm(0) {}
};

bool sorte(created& a, created& b) {
  if (a.sm != b.sm) {
    return a.sm < b.sm;
  }
  for (int i = 0; i < min(a.x.size(), b.x.size()); i++) {
    if (a.x[i] == b.x[i]) continue;
    return a.x[i] > b.x[i];
  }
  return false;
}

void merge(vector<created>& a, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<created> L(n1, created(a[0].x.size()));
  vector<created> R(n1, created(a[0].x.size()));
  for (int i = 0; i < n1; i++) L[i] = a[l + i];
  for (int i = 0; i < n2; i++) R[i] = a[m + i + 1];
  int i = 0, j = 0, k = l;
  while (i < n1 and j < n2) {
    if (sorte(L[i], R[j])) {
      a[k++] = L[i++];
    } else
      a[k++] = R[j++];
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];
}

void mergesort(vector<created>& a, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<created> a;
  for (int i = 0; i < n; i++) {
    a.emplace_back(m);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i].x[j];
      a[i].sm += a[i].x[j];
    }
  }
  mergesort(a, 0, a.size() - 1);
  reverse(a.begin(), a.end());
  for (created& w : a) {
    for (int i = 0; i < w.x.size(); i++) {
      cout << w.x[i] << " ";
    }
    cout << "\n";
  }
}