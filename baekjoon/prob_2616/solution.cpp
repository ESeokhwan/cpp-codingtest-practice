#include <bits/stdc++.h>
using namespace std;

int n, k;
int po[50000];
int po_acc[50000];
int dp[3][50000];

int gofd(int cnt, int idx) {
  if(dp[cnt][idx] != -1) return dp[cnt][idx];
  
  if(cnt == 0 && idx == 0) dp[cnt][idx] = po_acc[idx];
  else if(cnt == 0) dp[cnt][idx] = max(po_acc[idx], gofd(cnt, idx - 1));
  else if(idx == cnt * k) dp[cnt][idx] = gofd(cnt - 1, idx - k) + po_acc[idx];
  else dp[cnt][idx] = max(gofd(cnt, idx-1), gofd(cnt - 1, idx - k) + po_acc[idx]);
  return dp[cnt][idx];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for(int i = 0; i < n; i++) cin >> po[i];
  cin >> k;

  for(int i = n - 1; i >= 0; i--) {
	if(i == n - 1) po_acc[i] = po[i];
	else if(i > n - k - 1) po_acc[i] = po_acc[i + 1] + po[i];
	else po_acc[i] = po_acc[i + 1] + po[i] - po[i + k];
  }

  cout << gofd(2, n - 1) << "\n";
  return 0;
}
