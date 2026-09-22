#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;
  if (n < 2) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}