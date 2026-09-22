#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  stack<char> st;
  for (char& x : s) {
    if (!st.empty() and st.top() == x) {
      st.pop();
    } else
      st.push(x);
  }
  if (st.empty())
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}