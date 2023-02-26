#include <bits/stdc++.h>

using namespace std;

int n, k;

int t[100][2];
int v[100][2];

int dp[105][100005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> t[i][0] >> v[i][0] >> t[i][1] >> v[i][1];

  int prev_st = 0;
  for(int i = 0; i < n; i++) {
	if(t[i][0] > t[i][1]) {
	  int tmp = t[i][0];
	  t[i][0] = t[i][1];
	  t[i][1] = tmp;
	  
	  tmp = v[i][0];
	  v[i][0] = v[i][1];
	  v[i][1] = tmp;
	}
	for(int j = prev_st; j <= k; j++) {
	  if(j+t[i][0] > k) break;
	  dp[i+1][j+t[i][0]] = dp[i][j] + v[i][0];
	}
	for(int j = prev_st; j <= k; j++) {
	  if(j+t[i][1] > k) break;
	  dp[i+1][j+t[i][1]] = max(dp[i+1][j+t[i][1]], dp[i][j] + v[i][1]);
	}
	prev_st += t[i][0];
  }

  cout << dp[n][k] << "\n";
  return 0;
}
