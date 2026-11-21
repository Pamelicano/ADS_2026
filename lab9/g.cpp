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
  string s;
  cin >> s;
  vector<ll> pi = pref_func(s);
  int n = s.size();
  int cnt = 0;
  ll k = pi[n - 1];
  vector<int> ans;
  while (k > 0) {
    ans.push_back(n - k);
    k = pi[k - 1];
  }
  ans.push_back(n);
  sort(ans.begin(), ans.end());
  cout << ans[0];
}