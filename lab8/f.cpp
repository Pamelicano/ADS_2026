#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 31;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vl h1(n + 1, 0), h2(n + 1, 0);
  vl p1(n + 1, 1), p2(n + 1, 1);

  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a' + 1;
    h1[i + 1] = (h1[i] * BASE + c) % MOD1;
    h2[i + 1] = (h2[i] * BASE + c) % MOD2;
    p1[i + 1] = p1[i] * BASE % MOD1;
    p2[i + 1] = p2[i] * BASE % MOD2;
  }

  vector<map<ll, int>> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int l = 0; l + i <= n; l++) {
      int r = l + i;
      ll x = (h1[r] - h1[l] * p1[i] % MOD1 + MOD1) % MOD1;
      ll y = (h2[r] - h2[l] * p2[i] % MOD2 + MOD2) % MOD2;

      ll key = x * MOD2 + y;
      cnt[i][key]++;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int L, R;
    cin >> L >> R;
    int i = R - L + 1;
    int l = L - 1;
    int r = R;
    ll x = (h1[r] - h1[l] * p1[i] % MOD1 + MOD1) % MOD1;
    ll y = (h2[r] - h2[l] * p2[i] % MOD2 + MOD2) % MOD2;
    ll key = x * MOD2 + y;
    cout << cnt[i][key] << "\n";
  }
}