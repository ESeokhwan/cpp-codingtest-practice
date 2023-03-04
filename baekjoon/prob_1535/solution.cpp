#include <bits/stdc++.h>

using namespace std;

int n;
int l[20];
int j[20];

int res;

void bt(int acc, int lf, int idx) {
  if(lf <= 0) {
	res = max(res, 0);
	return;
  }
  if(idx == n) {
	res = max(res, acc);
	return;
  }
  bt(acc, lf, idx + 1);
  bt(acc + j[idx], lf - l[idx], idx + 1);
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  for(int i = 0; i < n; i++) cin >> j[i];

  res = 0;
  bt(0, 100, 0);
  cout << res << "\n";
  return 0;
}
