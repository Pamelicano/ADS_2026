#include <bits/stdc++.h>

using namespace std;

struct Date {
  int day, month, year;
};

bool lessDate(Date a, Date b) {
  if (a.year != b.year) return a.year < b.year;
  if (a.month != b.month) return a.month < b.month;
  return a.day < b.day;
}

void merge(vector<Date>& a, int l, int r, int m) {
  int n1 = m - l + 1;
  int n2 = r - m;
  vector<Date> L(n1), R(n2);
  for (int i = 0; i < n1; i++) L[i] = a[l + i];
  for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (!lessDate(L[i], R[j]))
      a[k++] = L[i++];
    else
      a[k++] = R[j++];
  }
  while (i < n1) a[k++] = L[i++];
  while (j < n2) a[k++] = R[j++];
}

void mergesort(vector<Date>& a, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, r, m);
  }
}

int main() {
  int n;
  cin >> n;
  vector<Date> a(n);
  for (int i = 0; i < n; i++) {
    char d;
    cin >> a[i].day >> d >> a[i].month >> d >> a[i].year;
  }
  mergesort(a, 0, n - 1);
  for (int i = n - 1; i >= 0; i--) {
    cout << setfill('0') << setw(2) << a[i].day << "-" << setw(2) << a[i].month
         << "-" << setw(4) << a[i].year << "\n";
  }
}