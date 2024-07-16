#include "bits/stdc++.h"
using namespace std;

int R, C;
int _map[1000][1000];

int dp[1000][1000];

int gofd(int x, int y) {
  if (dp[x][y] != -1) {
	return dp[x][y];
  }

  if (x == R - 1 && y == C - 1) {
	dp[x][y] = _map[x][y];
  } else if (x == R - 1) {
	dp[x][y] = gofd(x, y + 1) + _map[x][y];
  } else if (y == C - 1) {
	dp[x][y] = gofd(x + 1, y) + _map[x][y];
  } else {
	dp[x][y] = max(gofd(x + 1, y), gofd(x, y + 1)) + _map[x][y];
  }
  return dp[x][y];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  cin >> _map[i][j];
	}
  }
  memset(dp, -1, sizeof(dp));
  cout << gofd(0, 0) << "\n";
  return 0;
}
