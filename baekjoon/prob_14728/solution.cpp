#include <bits/stdc++.h>
using namespace std;

int n, t;
pair<int, int> probs[100];
int dp[100][10001];

int gofd(int idx1, int idx2) {
  if(idx2 < 0 || idx1 < 0) return 0;
  
  if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
  if(probs[idx1].first > idx2) {
	dp[idx1][idx2] = gofd(idx1 - 1, idx2);
  } else {
	dp[idx1][idx2] = max(
		gofd(idx1 - 1, idx2), 
		gofd(idx1 - 1, idx2 - probs[idx1].first) + probs[idx1].second);
  }
  return dp[idx1][idx2];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> n >> t;
  for(int i = 0; i < n; i++) cin >> probs[i].first >> probs[i].second;

  cout << gofd(n - 1, t) << "\n";
  return 0;
}
