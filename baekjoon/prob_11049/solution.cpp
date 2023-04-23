#include <bits/stdc++.h>
using namespace std;

int n;
int mats[500][2];

int dp[500][500];

int gof_dp(int st, int en) {
  if(dp[st][en] != -1) return dp[st][en];
  if(en == st) {
	return dp[st][en] = 0;
  }
  
  int tmp_res = 2000000000;
  for(int i = 0; i < en - st; i++) {
	tmp_res = min(tmp_res, gof_dp(st, st+i) + gof_dp(st + i + 1, en) 
		+ mats[st][0] * mats[st+i][1] * mats[en][1]);
  }
  return dp[st][en] = tmp_res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> n;
  for(int i = 0; i < n; i++) cin >> mats[i][0] >> mats[i][1];

  cout << gof_dp(0, n-1) << "\n";
  return 0;
}
