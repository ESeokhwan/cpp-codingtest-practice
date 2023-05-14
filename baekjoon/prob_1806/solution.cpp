#include <bits/stdc++.h>
using namespace std;

int n, s;
int nums[100000];
int sums_from_start[100001];
int res;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> s;
  for(int i = 0; i < n; i++) cin >> nums[i];

  sums_from_start[0] = 0;
  for(int i = 0; i < n; i++) sums_from_start[i+1] = sums_from_start[i] + nums[i];

  int en = -1;
  int st = 0;
  for(int i = 0; i <= n; i++) {
	if(sums_from_start[i] >= s) {
	  en = i;
	  break;
	}
  }

  res = 0;
  if(en != -1) {
	res = en;
	for(; en <= n; en++) {
	  for(; st < en; st++) {
		int tmp_s = sums_from_start[en] - sums_from_start[st];
		if(tmp_s < s) break;
		res = min(res, en - st);
	  }
	}
  }
  cout << res << "\n";
  return 0;
}
