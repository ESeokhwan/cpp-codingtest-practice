#include <bits/stdc++.h>
using namespace std;

int n, m;
bool pinned[40];

int dp[41];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(pinned, false, sizeof(pinned));

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
	int input;
	cin >> input;
	pinned[input-1] = true;
  }

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];

  int st = 0;
  int res = 1;
  for(int i = 0; i < n; i++) {
	if(pinned[i]) {
	  res *= dp[i - st];
	  st = i + 1;
	  continue;
	}
	if(i == n - 1) res *= dp[n - st];
  }

  cout << res << "\n";
  return 0;
}
