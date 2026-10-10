#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
 public:
  vector<int> a;

  void insert(int x) {
    a.push_back(x);
    int i = a.size() - 1;
    while (i > 0 and a[i] > a[(i - 1) / 2]) {
      swap(a[i], a[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  }
  int top() { return a[0]; }

  void heapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;

    if (l < a.size() and a[l] > a[m]) m = l;
    if (r < a.size() and a[r] > a[m]) m = r;

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
};

int main() {
  MaxHeap h;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    h.insert(x);
  }
  while (h.size() > 1) {
    int a = h.top();
    h.pop();
    int b = h.top();
    h.pop();
    if (a != b) {
      h.insert(a - b);
    }
  }
  if (h.size() == 0) {
    cout << "0\n";
    return 0;
  }
  cout << h.top() << "\n";
  return 0;
}