#include <bits/stdc++.h>

using namespace std;

bool solve(vector<vector<int>>& a, const vector<int>& b) {
  int k = b.size();
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      int u = b[i] - 1;
      int v = b[j] - 1;
      if (a[u][v] == 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  while (q--) {
    vector<int> b(3);
    for (int& x : b) {
      cin >> x;
    }
    if (solve(a, b)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
