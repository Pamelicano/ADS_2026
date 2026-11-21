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

string to_lower(string s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

int main() {
  string s;
  cin >> s;
  string ff = to_lower(s);
  int q;
  cin >> q;
  vector<string> ct(q);
  for (int i = 0; i < q; i++) {
    cin >> ct[i];
  }
  vector<ll> mt(q);
  for (int i = 0; i < q; i++) {
    string temp = to_lower(ct[i]);
    string w = temp + "#" + ff;
    vector<ll> pi = pref_func(w);
    mt[i] = pi.back();
    mx = max(mx, mt[i]);
  }
  vector<string> ans;
  for (int i = 0; i < q; i++) {
    if (mt[i] == mx and mx > 0) {
      ans.push_back(ct[i]);
    }
  }
  cout << ans.size() << "\n";
  for (auto& x : ans) cout << x << '\n';
}