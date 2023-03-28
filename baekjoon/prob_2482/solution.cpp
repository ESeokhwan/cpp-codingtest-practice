#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[1001][1001];

int fill_dp(int _n, int _k) {
  if(_n <= 0 || _k <= 0) return 0;
  if(dp[_n][_k] != -1) return dp[_n][_k];

  if(_k == 1) dp[_n][_k] = _n;
  else if(_n == 2 * _k) dp[_n][_k] = 2;
  else if(_n < 2 * _k) dp[_n][_k] = 0;
  else dp[_n][_k] = (fill_dp(_n-2, _k-1) + fill_dp(_n-1, _k)) % 1000000003;
  return dp[_n][_k];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i <= n; i++) {
	for(int j = 0; j <= n; j++) {
	  dp[i][j] = -1;
	}
  }

  cout << fill_dp(n, k) << "\n";
  return 0;
}
