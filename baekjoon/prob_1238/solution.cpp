#include <bits/stdc++.h>

using namespace std;

int n, m, x;
int dp[1000][1000];

const int INF = 10000000;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 

  cin >> n >> m >> x;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) dp[i][j] = INF;
  }
  
  for(int i = 0; i < m; i++) {
	int input[3];
	cin >> input[0] >> input[1] >> input[2];
	dp[input[0] - 1][input[1] - 1] = input[2];
  }
  for(int i = 0; i < n; i++) dp[i][i] = 0;

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  for(int k = 0; k < n; k++) {
		dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
	  }
	}
  }

  int res = 0;
  for(int i = 0; i < n; i++) res = max(res, dp[i][x - 1] + dp[x - 1][i]);

  cout << res << "\n";
  return 0;
}
