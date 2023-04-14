#include <bits/stdc++.h>
using namespace std;

int n;
int wine[10000];
int dp[10000];

int get_or_fill_dp(int idx) {
  if(idx < 0) return 0;
  if(dp[idx] != -1) return dp[idx];

  if(idx == 0) {
	dp[idx] = wine[idx];
  } else if(idx == 1) {
	dp[idx] = wine[idx] + wine[idx - 1];
  } else {
    int cand_a = get_or_fill_dp(idx-3) + wine[idx-1] + wine[idx];
    int cand_b = get_or_fill_dp(idx-2) + wine[idx];
    int cand_c = get_or_fill_dp(idx-1);

    dp[idx] = max(max(cand_a, cand_b), cand_c);
  }
  return dp[idx];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for(int i = 0; i < n; i++) cin >> wine[i];
  cout << get_or_fill_dp(n-1) << "\n";

  return 0;
}
