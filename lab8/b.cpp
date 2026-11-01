#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 911382323;

struct Hash {
  vector<ll> h1, h2;

  Hash(const string& s) {
    int n = s.size();
    h1.resize(n + 1, 0);
    h2.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a' + 1;
      h1[i + 1] = (h1[i] * BASE + c) % MOD1;
      h2[i + 1] = (h2[i] * BASE + c) % MOD2;
    }
  }

  pll get(int l, int r, const vector<ll>& p1, const vector<ll>& p2) {
    ll x = (h1[r] - h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1;
    ll y = (h2[r] - h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;
    return {x, y};
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a, b, p;
  cin >> a >> b >> p;
  int n = a.size(), k = b.size(), m = p.size();
  if (m > n || m > k) {
    cout << 0 << '\n';
    return 0;
  }

  vector<ll> pow1(max({n, k, m}) + 1, 1);
  vector<ll> pow2(max({n, k, m}) + 1, 1);

  for (int i = 1; i < (int)pow1.size(); i++) {
    pow1[i] = pow1[i - 1] * BASE % MOD1;
    pow2[i] = pow2[i - 1] * BASE % MOD2;
  }

  Hash ha(a), hb(b), hp(p);
  auto t = hp.get(0, m, pow1, pow2);
  int ans = 0;
  for (int i = 0; i + m <= n && i + m <= k; i++) {
    if (ha.get(i, i + m, pow1, pow2) == t &&
        hb.get(i, i + m, pow1, pow2) == t) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
