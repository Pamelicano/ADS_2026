#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll mx = -1e9;

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

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<ll> pi = pref_func(s);
    ll cnt = pi.back();
    cout << s.size() + (k - 1) * (s.size() - cnt) << "\n";
  }
}