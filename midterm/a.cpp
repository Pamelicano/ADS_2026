#include <bits/stdc++.h>

using namespace std;

class LinkedList {
 public:
  vector<int> a;

  void push_back(int x) { a.push_back(x); }
  void delete_x(int x) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == x) {
        a.erase(a.begin() + i);
      }
    }
  }
  void print() {
    for (int i = 0; i < a.size(); i++) {
      cout << a[i] << " ";
    }
  }
};

int main() {
  LinkedList ll;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ll.push_back(x);
  }
  int k;
  cin >> k;
  ll.delete_x(k);
  ll.print();
}