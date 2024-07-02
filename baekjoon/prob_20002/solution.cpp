#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll _map[300][300];

int dp[300][300][300];

int gofd(int r, int c, int k) {
  if (dp[r][c][k] != -1) return dp[r][c][k];

  if (k == 1) {
	dp[r][c][k] = _map[r][c];
  } else {
	dp[r][c][k] = gofd(r, c, k - 1);
	for (int i = 0; i < k; i++) {
	  dp[r][c][k] += _map[r + i][c + k - 1];
	  dp[r][c][k] += _map[r + k - 1][c + i];
	}
	dp[r][c][k] -= _map[r + k - 1][c + k - 1];
  }
  return dp[r][c][k];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  cin >> _map[i][j];
	}
  }
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  gofd(i, j, min(n - i, n - j));
	}
  }

  int res = -5000;
  for (int i = 0; i < n; i++) { 
	for (int j = 0; j < n; j++) {
	  for (int l = 0; l < min(n - i, n - j); l++) {
		res = max(res, dp[i][j][l + 1]);
	  }
	}
  }

  cout << res << "\n";
  return 0;
}
