#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> prefix_func(string s) {
  int n = (int)s.size();
  vector<ll> pi(n);
  for (ll i = 1; i < n; i++) {
    ll j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

bool find(string& s, string& pat) {
  string new_s = pat + "#" + s;
  vector<ll> pi = prefix_func(new_s);
  for (ll& x : pi) {
    if (x == (ll)pat.size()) return true;
  }
  return false;
}

int main() {
  string a, b;
  cin >> a >> b;
  string tmp = a;
  int l = 1, r = (b.size() + a.size() - 1) / a.size() + 1;
  while (l < r) {
    int m = l + (r - l) / 2;
    string cur = "";
    for (int i = 0; i < m; i++) cur += tmp;
    if (find(cur, b)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  string cur = "";
  for (int i = 0; i < l; i++) cur += tmp;
  if (find(cur, b))
    cout << l;
  else
    cout << "-1\n";
}