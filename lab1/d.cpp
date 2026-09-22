#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> primes(1e6 + 1, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i <= 1e6; i++) {
    if (primes[i]) {
      for (int j = i * i; j <= 1e6; j += i) {
        primes[j] = false;
      }
    }
  }
  vector<int> prime;
  for (int i = 2; i <= 1e6; i++) {
    if (primes[i]) prime.push_back(i);
  }
  cout << prime[n - 1] << "\n";
}