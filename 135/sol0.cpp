// #include "/home/totoro/.local/include/cpdebug.h"
// #include "cpdebug.h"
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v) {
  int n = v.size();
  int ans = 0;
  vector<int> b(n, 0);
  vector<int> dec;
  for (int i = 1; i < n; i++) {
    if (v[i] > v[i - 1])
      dec.push_back(i);
  }
  dec.push_back(n);
  int dc = 0;
  int inc = 0;
  for (int i = 0; i < n;) {
    int prev = v[dec[dc] - 1], k = 1;
    for (int j = dec[dc] - 1; j > i; j--) {
      if (v[j] == prev) {
        b[j] = k = 1;
      } else {
        b[j] = ++k;
      }
      prev = v[j];
    }

    if (v[i] != prev)
      k++;
    else
      k = 1;

    b[i] = max(inc + 1, k);
    inc = b[dec[dc] - 1];

    // debug(i, dc, dec, k);
    i = dec[dc];
    dc++;
  }
  for (int i = 0; i < n; i++)
    ans += b[i];
  debug(b);
  return ans;
}

int main() {
  vector<int> v = {1, 3, 2, 2, 1};
  cout << solve(v);
  return 0;
}