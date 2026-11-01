#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;
  ll pref = 0;

  for (int i = 0; i < n; i++) {
    ll p;
    cin >> p;
    ll v = (p - pref) / (1LL << i);
    cout << char(v + 97);
    pref = p;
  }
  cout << "\n";
  return 0;
}