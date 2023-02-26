#include <bits/stdc++.h>

using namespace std;

int m, n;
char g_map[50][50];
int dp[2501][50][50];

int r_off[4] = {1, -1, 0, 0};
int c_off[4] = {0, 0, 1, -1};

int ctoi(char c) {
  return (int) (c - '0');
}

bool update_dp(int cnt) {
  bool update = false;
  for(int cr = 0; cr < n; cr++) {
	for(int cc = 0; cc < m; cc++) {
	  if(dp[cnt][cr][cc] != cnt) continue;
	  for(int i = 0; i < 4; i++) {
		int nr = cr + ctoi(g_map[cr][cc]) * r_off[i];
		int nc = cc + ctoi(g_map[cr][cc]) * c_off[i];

		if(nr < 0 || nr >= n || nc < 0|| nc >= m) continue;
		if(g_map[nr][nc] == 'H') continue;
		dp[cnt+1][nr][nc] = cnt+1;
		update = true;
	  }
	  dp[cnt+1][cr][cc] = max(dp[cnt+1][cr][cc], dp[cnt][cr][cc]);
	}
  }
  return update;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 2501; i++) {
	for(int j = 0; j < 50; j++) memset(dp[i][j], -1, sizeof(int)*50);
  }

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  cin >> g_map[i][j];
	}
  }

  int res = -1;
  dp[0][0][0] = 0;
  for(int i = 0; i < 2500; i++) {
	if(!update_dp(i)) {
	  res = i+1;
	  break;
	}
  }

  cout << res << "\n";
  return 0;
}
