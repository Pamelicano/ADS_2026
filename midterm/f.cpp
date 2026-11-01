#include <bits/stdc++.h>

using namespace std;

class LinkedList {
 public:
  vector<int> a;

  void insert(int x) { a.push_back(x); }

  void insert_in_pos(int i, int x) { a.insert(a.begin() + i, x); }

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
    ll.insert(x);
  }
  int pos, y;
  cin >> pos >> y;
  ll.insert_in_pos(pos, y);
  ll.print();
}