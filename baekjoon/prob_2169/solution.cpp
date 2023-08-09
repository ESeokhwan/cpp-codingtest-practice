#include <bits/stdc++.h>
using namespace std;

int n, m;
int _map[1000][1000];

int dp[1000][1000];
int sub_dp1[1000];
int sub_dp2[1000];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  cin >> _map[i][j];
	}
  }

  for(int i = 0; i < n; i++) {
	if(i == 0) {
	  for(int j = 0; j < m; j++) {
		if(j == 0) dp[i][j] = _map[i][j];
		else dp[i][j] = dp[i][j - 1] + _map[i][j];
	  }
	} else {
	  for(int j = 0; j < m; j++) {
		if(j == 0) sub_dp1[j] = dp[i - 1][j] + _map[i][j];
		else sub_dp1[j] = max(dp[i - 1][j], sub_dp1[j - 1]) + _map[i][j];
	  }
	  for(int j = m - 1; j >= 0; j--) {
		if(j == m - 1) sub_dp2[j] = dp[i - 1][j] + _map[i][j];
		else sub_dp2[j] = max(dp[i - 1][j], sub_dp2[j + 1]) + _map[i][j];
	  }
	  for(int j = 0; j < m; j++) {
		dp[i][j] = max(sub_dp1[j], sub_dp2[j]);
	  } 
	}
  }
  cout << dp[n - 1][m - 1] << "\n";
  return 0;
}
