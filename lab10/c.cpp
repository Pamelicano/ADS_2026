#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> par(2 * max(n, m) + 67, -1);
  queue<int> q;
  q.push(n);
  par[n] = n;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == m) break;
    int u = v * 2;
    if (u < par.size() and par[u] == -1) {
      par[u] = v;
      q.push(u);
    }
    int u2 = v - 1;
    if (u2 >= 0 and par[u2] == -1) {
      par[u2] = v;
      q.push(u2);
    }
  }
  vector<int> ans;
  int cur = m;
  while (cur != n) {
    ans.push_back(cur);
    cur = par[cur];
  }
  cout << ans.size() << "\n";
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
  return 0;
}