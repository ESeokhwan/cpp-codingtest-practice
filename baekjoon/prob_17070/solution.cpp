#include<bits/stdc++.h>

using namespace std;

int n;
int p_map[16][16];
int dp[3][16][16];

pair<int, int> dirs[3] = {
  make_pair(0, 1),
  make_pair(1, 1),
  make_pair(1, 0)
};

bool is_clear(int r, int c, pair<int, int> dir) {
  int fr = r - dir.first;
  int fc = c - dir.second;
  if(fr < 0 || fc < 0) return false;
  return p_map[fr][fc] == 0 && p_map[r][fc] == 0 && p_map[fr][c] == 0 && p_map[r][c] == 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, 0, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  cin >> p_map[i][j];
	}
  }

  dp[0][0][1] = 1;
  for(int r = 0; r < n; r++) {
	for(int c = 0; c < n; c++) {
	  for(int i = 0; i < 3; i++) {
		pair<int, int> dir = dirs[i];
		int nr = r + dir.first;
		int nc = c + dir.second;
		if(nr >= n || nc >= n) continue;
		if(!is_clear(nr, nc, dir)) continue;
		else if(i == 0) dp[i][nr][nc] += (dp[0][r][c] + dp[1][r][c]);
		else if(i == 1) dp[i][nr][nc] += (dp[0][r][c] + dp[1][r][c] + dp[2][r][c]);
		else if(i == 2) dp[i][nr][nc] += (dp[1][r][c] + dp[2][r][c]);
	  }
	}
  }

  cout << dp[0][n-1][n-1] + dp[1][n-1][n-1] + dp[2][n-1][n-1] << "\n";
  return 0;
}
