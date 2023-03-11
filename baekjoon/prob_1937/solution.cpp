#include <bits/stdc++.h>
using namespace std;

int n;
int p_map[500][500];
int dp[500][500];

pair<int, int> offs[4] = {
  make_pair(1, 0),
  make_pair(0, 1),
  make_pair(-1,0),
  make_pair(0,-1)
};

int fill_dp(int r, int c) {
  if(dp[r][c] != -1) return dp[r][c];
  
  int res = 1;
  for(pair<int, int> off : offs) {
	int nr = r + off.first;
	int nc = c + off.second;

	if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
	if(p_map[nr][nc] > p_map[r][c]) {
	  res = max(res, fill_dp(nr, nc)+1);
	}
  }
  dp[r][c] = res;
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  cin >> p_map[i][j];
	}
  }

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  fill_dp(i, j);
	}
  }
  
  int res = 0;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  res = max(res, dp[i][j]);
	}
  }
  
  cout << res << "\n";
  return 0;
}
