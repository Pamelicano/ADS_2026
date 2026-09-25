#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<char> a(n);
  for (char& x : a) cin >> x;
  deque<char> q;
  map<char, int> cnt;
  for (char& x : a) {
    cnt[x]++;
    if (cnt[x] <= 1) q.push_front(x);
    if (cnt[x] > 1 and x == q.back()) q.pop_back();
    if (!q.empty()) {
      cout << q.back() << " ";
    } else
      cout << "-1 ";
    // cout << "\n";
    // for (auto& x : q) cout << x << " ";
    // cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}