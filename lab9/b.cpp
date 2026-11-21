#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll mx = -1e9;

vector<ll> prefix_func(string& s) {
  int n = (int)s.size();
  vector<ll> pi(n);
  for (ll i = 1; i < n; i++) {
    ll j = pi[i - 1];
    while (j > 0 and s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int main() {}