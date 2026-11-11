#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
int MOD = 1e9 + 7;

ull binpow(ull a, int n) {
  ull res = 1;
  while (n != 0) {
    if (n & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

string to_hashing(string& s) {
  ull h = 0;
  for (int i = 0; i < s.size(); i++) {
    h = (h + (s[i] - 47) * binpow(11, i)) % MOD;
  }
  return to_string(h);
}

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  vector<string> v;
  for (int i = 0; i < 2 * n; i++) {
    string s;
    cin >> s;
    mp[s]++;
    v.push_back(s);
  }
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    if (cnt == n) break;
    string hs = to_hashing(v[i]);
    if (mp.count(hs)) {
      cout << "Hash of string \"" << v[i] << "\" is " << hs << "\n";
      cnt++;
    }
  }
}