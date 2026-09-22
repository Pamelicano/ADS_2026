#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  ll n;
  cin >> n;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        cout << i << " ";
        n /= i;
      }
    }
  }
  if (n != 0) cout << n << "\n";
  return 0;
}