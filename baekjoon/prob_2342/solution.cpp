#include <bits/stdc++.h>
using namespace std;

int input[100001];
int dp[100000][5][5];

void fill_dp(int x, int y, int z, int val) {
  if(dp[x][y][z] == -1) {
	dp[x][y][z] = val;
	return;
  }
  dp[x][y][z] = min(dp[x][y][z], val);
  return;
}

int n_po(int prev, int cur) {
  if(prev == cur) return 1;
  if(prev == 0) return 2;
  if((prev - cur) % 2 != 0) return 3;
  return 4;
}

void fill(int idx) {
  int tar = input[idx];

  for(int i = 0; i < 5; i++) {
	for(int j = 0; j < 5; j++) {
	  if(dp[idx-1][i][j] == -1) continue;
	  if(j != tar) fill_dp(idx, tar, j, dp[idx-1][i][j] + n_po(i, tar));
	  if(i != tar) fill_dp(idx, i, tar, dp[idx-1][i][j] + n_po(j, tar));
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  memset(dp, -1, sizeof(dp));

  int idx = 0;
  while(true) {
	cin >> input[idx];
	if(input[idx++] == 0) break;
  }

  for(int i = 0; i < idx - 1; i++) {
	if(i == 0) {
	  dp[i][0][input[i]] = 2;
	  dp[i][input[i]][0] = 2;
	} else {
	  fill(i);
	}
  }

  int res = 99999999;
  for(int i = 0; i < 5; i++) {
	for(int j = 0; j < 5; j++) {
	  if(dp[idx - 2][i][j] == -1) continue;
	  res = min(res, dp[idx - 2][i][j]);
	}
  }
  cout << res << "\n";
  return 0;
}
