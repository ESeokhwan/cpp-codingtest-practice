#include <bits/stdc++.h>
using namespace std;

int INF = 10000000;
int n;
int price[1000][3];

int dp[1000][3][3];

int gofd(int x1, int x2, int x3) {
  if(dp[x1][x2][x3] != INF) return dp[x1][x2][x3];
  if(x1 == 0) {
	if(x2 == x3) return dp[x1][x2][x3] = price[x1][x2];
	else return INF;
  }

  if(x1 == n-1 && x2 == x3) return INF;
  for(int i = 0; i < 3; i++) {
	if(x2 == i) continue;
	dp[x1][x2][x3] = min(dp[x1][x2][x3], gofd(x1-1, i, x3) + price[x1][x2]);
  }
  return dp[x1][x2][x3];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> price[i][0] >> price[i][1] >> price[i][2];

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < 3; j++) {
	  for(int k = 0; k < 3; k++) dp[i][j][k] = INF;
	}
  }

  int res = INF;
  for(int i = 0; i < 3; i++) {
	for(int j = 0; j < 3; j++) {
	  res = min(res, gofd(n-1, i, j));
	}
  }

  cout << res << "\n";
  return 0;
}
