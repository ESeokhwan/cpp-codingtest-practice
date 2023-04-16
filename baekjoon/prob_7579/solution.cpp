#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> me[101];
int dp[101][10001];

int get_res() {
  for(int i = 0; i <= 10000; i++) {
	for(int j = 0; j <= n; j++) {
	  if(dp[j][i] >= m) return i;
	}
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> me[i].first;
  for(int i = 1; i <= n; i++) cin >> me[i].second;

  for(int i = 0; i <= 10000; i++) dp[0][i] = 0;

  for(int i = 1; i <= n; i++) {
	for(int j = 0; j <= 10000; j++) {
	  if(me[i].second > j) dp[i][j] = dp[i-1][j];
	  else dp[i][j] = max(dp[i-1][j], dp[i-1][j - me[i].second] + me[i].first);
	}
  }
  
  cout << get_res() << "\n";
  return 0;
}
