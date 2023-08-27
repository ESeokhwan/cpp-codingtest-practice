#include <bits/stdc++.h>
using namespace std;

int UNDER_BOUND = -10000000;

int n, m;
int nums[100];

int submax[105][105];
int dp[105][105];

void init_submax() {
  for(int i = 0; i < n; i++) {
	int acc = 0;
	int tmp_max = UNDER_BOUND;
	for(int j = i; j < n; j++) {
	  if(acc < 0) acc = 0;
	  acc += nums[j];
	  tmp_max = max(tmp_max, acc);
	  submax[i][j + 1] = tmp_max;
	}
  }
}

void init_dp() {
  for(int i = 0; i <= n; i++) {
	for(int j = 0; j <= m; j++) {
	  dp[i][j] = UNDER_BOUND;
	}
  }
}

int gofd(int x, int y) {
  if(dp[x][y] != UNDER_BOUND) return dp[x][y];  
  if(x < 2 * (y - 1) + 1) return dp[x][y];

  if(y == 1) {
	dp[x][y] = submax[0][x];
  } else if(x == 2 * (y - 1) + 1) {
	int tmp = 0;
	for(int i = 0; i < x; i++) {
	  if(i % 2 == 0) tmp += nums[i];
	}
	dp[x][y] = tmp;
  } else {
	dp[x][y] = gofd(x - 1, y);
	for(int i = 2 * (y - 2); i < x - 2; i++) {
	  dp[x][y] = max(dp[x][y], gofd(i + 1, y - 1) + submax[i + 2][x]);
	}
  }
  return dp[x][y];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> nums[i];

  init_submax();
  init_dp();

  cout << gofd(n, m) << "\n";
  return 0;
}
