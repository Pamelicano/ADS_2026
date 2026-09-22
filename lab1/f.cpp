#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  stack<char> sa, sb;
  for (char& x : a) {
    if (x != '#')
      sa.push(x);
    else
      sa.pop();
  }
  for (char& x : b) {
    if (x != '#')
      sb.push(x);
    else
      sb.pop();
  }
  if (sa == sb) {
    cout << "Yes\n";
  } else
    cout << "No\n";
  return 0;
}