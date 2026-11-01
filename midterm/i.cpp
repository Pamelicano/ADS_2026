#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  if (b % a == 0) return a;
  if (a > b) return gcd(a % b, b);
  return gcd(a, b % a);
}

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

int main() {
  ll a, b;
  cin >> a >> b;
  cout << gcd(a, b) << " " << lcm(a, b) << "\n";
}