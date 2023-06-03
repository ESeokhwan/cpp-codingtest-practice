#include <bits/stdc++.h>
using namespace std;

int t, n;
int input[100000][2];
int dp[100001][3];

int fogd(int idx1, int idx2) {
  if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

  if(idx1 == 0) dp[idx1][idx2] = 0;
  else {
	if(idx2 == 0) {
	  dp[idx1][idx2] = max(fogd(idx1-1, 1), fogd(idx1-1, 2)) + input[idx1-1][0];
	} else if(idx2 == 1) {
	  dp[idx1][idx2] = max(fogd(idx1-1, 0), fogd(idx1-1, 2)) + input[idx1-1][1];
	} else {
	  dp[idx1][idx2] = max(fogd(idx1-1, 0), max(fogd(idx1-1, 1), fogd(idx1-1, 2)));
	}
  }
  return dp[idx1][idx2];
}

void solution() {
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for(int i = 0; i < n; i++) cin >> input[i][0];
  for(int i = 0; i < n; i++) cin >> input[i][1];

  cout << max(fogd(n, 0), max(fogd(n, 1), fogd(n, 2))) << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for(int i = 0; i < t; i++) solution();
  return 0;
}
