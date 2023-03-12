#include <bits/stdc++.h>
using namespace std;

int m, n;
int g_map[500][500];
int dp[500][500];

int fill_dp(int r, int c) {
  if(r >= m || c >= n) return 0;
  if(dp[r][c] != -1) return dp[r][c];

  int res = 0;
  if(r == m - 1 && c == n - 1) res += 1;
  if(r + 1 < m && g_map[r][c] > g_map[r + 1][c]) res += fill_dp(r + 1, c);
  if(c + 1 < n && g_map[r][c] > g_map[r][c + 1]) res += fill_dp(r, c + 1);
  if(r - 1 >= 0 && g_map[r][c] > g_map[r - 1][c]) res += fill_dp(r - 1, c);
  if(c - 1 >= 0 && g_map[r][c] > g_map[r][c - 1]) res += fill_dp(r, c - 1);
  
  dp[r][c] = res;
  return dp[r][c];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  cin >> m >> n;
  for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  cin >> g_map[i][j];
	}
  }

  cout << fill_dp(0,0) <<  "\n";
  return 0;
}
