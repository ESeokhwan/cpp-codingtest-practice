#include <bits/stdc++.h>

using namespace std;

int n, k;
int w[100];
int v[100];

int dp[101][100005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  memset(dp, 0, sizeof(dp));

  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> w[i] >> v[i];

  memset(dp[0], 0, sizeof(int)*(k+1));
  for(int i = 1; i <= n; i++) {
	for(int j = 0; j <= k; j++) {
	  if(j < w[i-1]) {
		dp[i][j] = dp[i-1][j];
		continue;
	  }
	  dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
	}
  }

  cout << dp[n][k] << "\n";
  return 0;
}
