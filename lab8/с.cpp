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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n and n != 0) {
    vector<string> p;
    for (int i = 0; i < n; i++) {
      string x;
      cin >> x;
      p.push_back(x);
    }
    string txt;
    cin >> txt;
    vector<int> freq(n, 0);
    int mx_freq = -1;
    for (int i = 0; i < n; i++) {
      string s = p[i] + "#" + txt;
      vector<ll> pi = prefix_func(s);

      int m = p[i].size();
      for (int j = m + 1; j < s.size(); j++) {
        if (pi[j] == m) {
          freq[i]++;
        }
      }
      mx_freq = max(mx_freq, freq[i]);
    }
    cout << mx_freq << "\n";
    for (int i = 0; i < n; i++) {
      if (freq[i] == mx_freq) {
        cout << p[i] << "\n";
      }
    }
  }
}
