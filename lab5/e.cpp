#include <bits/stdc++.h>

using namespace std;

#define ll long long

class MinHeap {
 public:
  vector<long long> a;

  void insert(long long x) {
    a.push_back(x);
    int i = a.size() - 1;
    while (i > 0 and a[i] < a[(i - 1) / 2]) {
      swap(a[i], a[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }

  void heapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;

    if (l < a.size() and a[l] < a[m]) m = l;
    if (r < a.size() and a[r] < a[m]) m = r;

    if (m != i) {
      swap(a[i], a[m]);
      heapify(m);
    }
  }

  void pop() {
    a[0] = a.back();
    a.pop_back();
    if (!a.empty()) heapify(0);
  }

  int size() { return a.size(); }

  long long top() { return a[0]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  MinHeap h;
  int q, k;
  cin >> q >> k;
  ll ans = 0;
  while (q--) {
    string cmd;
    cin >> cmd;
    if (cmd == "print") {
      cout << ans << "\n";
    } else {
      ll x;
      cin >> x;
      h.insert(x);
      ans += x;
      if (h.size() > k) {
        ans -= h.top();
        h.pop();
      }
    }
  }
  return 0;
}