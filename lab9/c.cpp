#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> pref_func(string& s) {
  int n = s.size();
  vector<ll> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 and s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int find(string& t, string& s) {
  string new_s = t + '#' + s;
  vector<ll> pi = pref_func(new_s);
  for (int i = 0; i < new_s.size(); i++) {
    if (pi[i] == (ll)t.size()) {
      return i - 2 * t.size();
    }
  }
  return -1;
}

int main() {
  string s, t;
  cin >> s >> t;
  string new_s = s + s;

  if (find(t, new_s) != -1) {
    cout << (s.size() - find(t, new_s)) % s.size();
  } else
    cout << -1;
}