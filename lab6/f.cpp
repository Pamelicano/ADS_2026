#include <bits/stdc++.h>
using namespace std;

struct Student {
  string ln, fn;
  double gpa;
};

double grade(string s) {
  if (s == "A+") return 4.00;
  if (s == "A") return 3.75;
  if (s == "B+") return 3.50;
  if (s == "B") return 3.00;
  if (s == "C+") return 2.50;
  if (s == "C") return 2.00;
  if (s == "D+") return 1.33;
  if (s == "D") return 1.50;
  return 0.00;
}

bool lessStu(const Student& a, const Student& b) {
  if (a.gpa != b.gpa) return a.gpa < b.gpa;
  if (a.ln != b.ln) return a.ln < b.ln;
  return a.fn < b.fn;
}

void heapify(vector<Student>& a, int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int m = i;

  if (l < n and lessStu(a[m], a[l])) m = l;
  if (r < n and lessStu(a[m], a[r])) m = r;
  if (m != i) {
    swap(a[i], a[m]);
    heapify(a, n, m);
  }
}

void heapsort(vector<Student>& a) {
  int n = a.size();
  for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(a[0], a[i]);
    heapify(a, i, 0);
  }
}

int main() {
  int n;
  cin >> n;
  vector<Student> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].ln >> a[i].fn;
    int sub, tt = 0;
    cin >> sub;
    double sm = 0;
    for (int j = 0; j < sub; j++) {
      string s;
      int crs;
      cin >> s >> crs;

      sm += grade(s) * crs;
      tt += crs;
    }
    a[i].gpa = sm / tt;
  }
  heapsort(a);
  cout << fixed << setprecision(3);
  for (const Student& x : a) {
    cout << x.ln << " " << x.fn << " " << x.gpa << "\n";
  }
}