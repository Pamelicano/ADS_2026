#include <bits/stdc++.h>

using namespace std;

class LinkedList {
 public:
  vector<int> a;

  void push_back(int x) { a.push_back(x); }
  void reverse_k() { reverse(a.begin(), a.end()); }

  void print() {
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  }
};

int main() {
  LinkedList ll;
  int n;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;
    ll.push_back(x);
  }

  ll.reverse_k();
  ll.print();
}