#include <bits/stdc++.h>
using namespace std;

int n;
int nums[2000];
int dp[2000];

/*
int gofd(int x) {
  if (dp[x] != -1) {
	return dp[x];
  }

  if (x == 0) {
	dp[x] = 1;
  } else {
	for (int i = 0; i < x; i++) {
	  int res = 1;
	  if (nums[x] > nums[i]) {
		res = max(res, 1 + gofd(i));
	  }
	}
	dp[x] = res;
  }
  return dp[x];
}
*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  memset(nums, -1, sizeof(nums));
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];

  int res = 0;
  for (int i = n - 1; i >= 0; i--) {
	dp[i] = 1;
	for (int j = n - 1; j > i; j--) {
	  if (nums[i] > nums[j]) {
		dp[i] = max(dp[i], 1 + dp[j]);
	  }
	}
	res = max(res, dp[i]);
  }

  cout << n - res << "\n";
  return 0;
}
