// zaebala zadacha

#include <bits/stdc++.h>
using namespace std;

vector<pair<string, string>> a;
map<string, string> mp, pr;

void heapify(int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && a[l].first > a[largest].first) largest = l;
  if (r < n && a[r].first > a[largest].first) largest = r;

  if (largest != i) {
    swap(a[i], a[largest]);
    heapify(n, largest);
  }
}

void heapSort() {
  int n = a.size();
  for (int i = n / 2 - 1; i >= 0; i--) heapify(n, i);
  for (int i = n - 1; i > 0; i--) {
    swap(a[0], a[i]);
    heapify(i, 0);
  }
}

int main() {
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    string u, v;
    cin >> u >> v;

    if (pr.count(u)) {
      mp[pr[u]] = v;
      pr[v] = pr[u];
    } else {
      mp[u] = v;
      pr[v] = u;
    }
  }
  for (auto& [key, val] : mp) a.push_back({key, val});
  heapSort();
  cout << a.size() << "\n";
  for (auto& [key, val] : a) cout << key << " " << val << "\n";
}