#include <bits/stdc++.h>

using namespace std;

void heapify(vector<char>& a, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int m = i;

  if (l < n and a[l] > a[m]) m = l;
  if (r < n and a[r] > a[m]) m = r;
  if (m != i) {
    swap(a[i], a[m]);
    heapify(a, n, m);
  }
}

void heapsort(vector<char>& a) {
  int n = a.size();
  for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(a[0], a[i]);
    heapify(a, i, 0);
  }
}

int main() {
  int n;
  cin >> n;
  vector<char> a(n);
  for (char& x : a) cin >> x;
  heapsort(a);
  char d;
  cin >> d;
  for (char& x : a) {
    if (d < x) {
      cout << x << "\n";
      return 0;
    }
  }
  cout << a[0] << "\n";
}
