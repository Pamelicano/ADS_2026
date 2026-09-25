#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (string& x : a) cin >> x;
  deque<string> q;
  for (string& x : a) {
    if (q.empty() or q.back() != x) q.push_back(x);
  }
  cout << q.size() << "\n";
  for (string& x : q) cout << x << "\n";
}