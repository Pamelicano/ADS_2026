#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

void heapify(vector<pair<string, int>>& a, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int m = i;
  if (l < n and compare(a[m], a[l])) m = l;
  if (r < n and compare(a[m], a[r])) m = r;
  if (m != i) {
    swap(a[m], a[i]);
    heapify(a, n, m);
  }
}

void heapsort(vector<pair<string, int>>& a) {
  int n = a.size();
  for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
  for (int i = n - 1; i > 0; i--) {
    swap(a[i], a[0]);
    heapify(a, i, 0);
  }
}
int main() {
  int n;
  cin >> n;
  vector<pair<string, int>> a(n);
  for (pair<string, int>& x : a) cin >> x.first >> x.second;
  heapsort(a);
  for (pair<string, int>& x : a) {
    cout << x.first << " " << x.second << "\n";
  }
}