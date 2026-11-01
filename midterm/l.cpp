#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> is_prime(1e4 + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= 1e4; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= 1e4; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= 1e4; i++) {
    if (is_prime[i]) {
      if (i > n) {
        cout << primes.size() << "\n";
        break;
      }
      primes.push_back(i);
    }
  }
}