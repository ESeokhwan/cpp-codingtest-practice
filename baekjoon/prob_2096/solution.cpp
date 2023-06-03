#include <bits/stdc++.h>
using namespace std;

int n;
char input[100000][3];
int dp[100000][3];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> input[i][0] >> input[i][1] >> input[i][2];
	input[i][0] = input[i][0] - '0';
	input[i][1] = input[i][1] - '0';
	input[i][2] = input[i][2] - '0';
  }

  dp[0][0] = input[0][0];
  dp[0][1] = input[0][1];
  dp[0][2] = input[0][2];
  for(int i = 1; i < n; i++) {
	dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + input[i][0];
	dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + input[i][2];
	dp[i][1] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2])) + input[i][1];
  }
  cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << " ";
  
  for(int i = 1; i < n; i++) {
	dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + input[i][0];
	dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + input[i][2];
	dp[i][1] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + input[i][1];
  }
  cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])) << " ";
  cout << "\n";
  return 0;
}
