#include <bits/stdc++.h>
using namespace std;

int n, m;
int b_map[1000][1000];
int h_dp[1000][1000];
int v_dp[1000][1000];
int t_dp[1000][1000];

int fill_h_dp(int r, int c) {
  if(r >= n || c >= m) return 0;
  if(h_dp[r][c] != -1) return h_dp[r][c];
  
  int res;
  int tmp = fill_h_dp(r, c + 1);
  if(b_map[r][c] == 0) res = 0;
  else res = tmp + 1;

  h_dp[r][c] = res;
  return h_dp[r][c];
}

int fill_v_dp(int r, int c) {
  if(r >= n || c >= m) return 0;
  if(v_dp[r][c] != -1) return v_dp[r][c];
  
  int res;
  int tmp = fill_v_dp(r + 1, c);
  if(b_map[r][c] == 0) res = 0;
  else res = tmp + 1;
  
  v_dp[r][c] = res;
  return v_dp[r][c];
}

int fill_t_dp(int r, int c) {
  if(r >= n || c >= m) return 0;
  if(t_dp[r][c] != -1) return t_dp[r][c];

  int res;
  int tmp = fill_t_dp(r + 1, c + 1);
  if(b_map[r][c] == 0) res = 0;
  else res = min(tmp + 1, min(h_dp[r][c], v_dp[r][c]));

  t_dp[r][c] = res;
  return t_dp[r][c];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(h_dp, -1, sizeof(h_dp));
  memset(v_dp, -1, sizeof(v_dp));
  memset(t_dp, -1, sizeof(t_dp));

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	string input;
	cin >> input;
	for(int j = 0; j < m; j++) b_map[i][j] = (int) (input[j] - '0');
  }

  for(int i = 0; i < n; i++) fill_h_dp(i, 0); 
  for(int i = 0; i < m; i++) fill_v_dp(0, i);
  for(int i = 0; i < n; i++) fill_t_dp(i, 0);
  for(int i = 0; i < m; i++) fill_t_dp(0, i);

  int res = 0;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  res = max(res, t_dp[i][j]);
	}
  }

  cout << res * res << "\n";
  return 0;
}
