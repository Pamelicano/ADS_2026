#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  stack<int> st;
  for (int& x : a) {
    while (!st.empty() and st.top() > x) {
      st.pop();
    }
    if (st.empty())
      cout << "-1 ";
    else
      cout << st.top() << " ";
    st.push(x);
  }
}