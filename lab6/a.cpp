#include <bits/stdc++.h>

using namespace std;

void merge(vector<char>& a, int l, int r, int m) {
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

void mergesort(vector<char>& a, int l, int r) {
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
  string s;
  cin >> s;
  vector<char> a, b;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or
        s[i] == 'u') {
      a.push_back(s[i]);
    } else
      b.push_back(s[i]);
  }
  mergesort(a, 0, a.size() - 1);
  mergesort(b, 0, b.size() - 1);
  for (char x : a) cout << x;
  for (char x : b) cout << x;
}