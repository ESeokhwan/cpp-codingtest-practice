#include "bits/stdc++.h"
using namespace std;

int n;
pair<int, int> meetings[100000];
int st_time[100000];
int en_time[100000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> st_time[i] >> en_time[i];
  }
  sort(st_time, st_time + n);
  sort(en_time, en_time + n);

  int res = 0;
  int tmp_res = 0;

  int st_idx = 0;
  int en_idx = 0;
  while (en_idx < n && st_idx < n) {
	if (en_idx == st_idx || st_time[st_idx] < en_time[en_idx]) {
	  tmp_res += 1;
	  st_idx += 1;
	} else {
	  tmp_res -= 1;
	  en_idx += 1;
	}
	res = max(res, tmp_res);
  }

  cout << res << "\n";
  return 0;
}
