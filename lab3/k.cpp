#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define ll long long

int main() {
  int q;
  cin >> q;
  vector<int> a(q);
  for (int& x : a) cin >> x;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> b(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }
  for (int x : a) {
    bool found = false;
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      int mx = max(b[mid][0], b[mid][m - 1]);
      if (mx >= x) {
        l = mid;
      } else
        r = mid - 1;
    }
    int row = l;
    int lf = 0, ri = m - 1;
    while (lf <= ri) {
      int mid = (lf + ri) / 2;
      if (b[row][mid] == x) {
        cout << row << " " << mid << "\n";
        found = true;
        break;
      }
      if (row & 1) {
        if (b[row][mid] < x) {
          lf = mid + 1;
        } else
          ri = mid - 1;
      } else {
        if (b[row][mid] > x) {
          lf = mid + 1;
        } else
          ri = mid - 1;
      }
    }
    if (!found) cout << "-1\n";
  }
}
