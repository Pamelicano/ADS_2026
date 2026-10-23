#include <bits/stdc++.h>

using namespace std;

void merge(vector<string>& a, int l, int r, int m) {
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<string> L(n1), R(n2);
  for (int i = 0; i < n1; i++) L[i] = a[l + i];
  for (int i = 0; i < n2; i++) R[i] = a[m + i + 1];
  int i = 0, j = 0, k = l;
  while (i < n1 and j < n2) {
    if (L[i].size() <= R[j].size())
      a[k++] = L[i++];
    else
      a[k++] = R[j++];
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];
}

void mergesort(vector<string>& a, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, r, m);
  }
}

void solve() {
  string s;
  getline(cin, s);

  stringstream ss(s);
  vector<string> a;
  string word;
  while (ss >> word) {
    a.push_back(word);
  }
  mergesort(a, 0, a.size() - 1);
  for (string& x : a) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (t--) {
    solve();
  }
}