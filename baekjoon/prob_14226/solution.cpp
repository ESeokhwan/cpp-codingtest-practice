#include <bits/stdc++.h>
using namespace std;

int n;

int dp[2001][2001];

int gofd(int val, int clip_board) {
  int res = 50000;
  if (val > 2 * n || clip_board > 2 * n || val < 0) {
	return res;
  }
  if (val == n) {
	dp[val][clip_board] = 0;
	return dp[val][clip_board];
  }
  if (dp[val][clip_board] != -1) return dp[val][clip_board];
  
  if (val != clip_board) {
    res = min(res, gofd(val, val) + 1);
    dp[val][clip_board] = res;
  }
  res = min(res, gofd(val - 1, clip_board) + 1);
  dp[val][clip_board] = res;
  if (clip_board != 0) {
    res = min(res, gofd(val + clip_board, clip_board) + 1);
    dp[val][clip_board] = res;
  }
  return dp[val][clip_board];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(dp, -1, sizeof(dp));

  cin >> n;
  cout << gofd(1, 0) << "\n";
  return 0;
}
