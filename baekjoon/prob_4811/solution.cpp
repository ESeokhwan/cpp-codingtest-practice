#include <bits/stdc++.h>
using namespace std;

int input[1000];

long long dp[61][31];

void solution(int n) {
  memset(dp, 0, sizeof(dp));

  for(int i = 1; i <= 2 * n; i++) {
	if(i <= n) dp[i][0] = 1;
	for(int j = 1; j <= i / 2; j++) {
	  if(i - j > n) continue;
	  dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}
  }
 
  long long res = 0;
  for(int i = 0; i <= n; i++) res += dp[2 * n][i];
  cout << res << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 1000; i++) {
	cin >> input[i];
	if(input[i] == 0) break;
	solution(input[i]);
  }
  return 0;
}
