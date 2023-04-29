#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> dp[1000001];

void init_dp() {
  for(int i = 0; i <= n; i++) dp[i] = make_pair(0, -1);
}

void fill_dp(int idx, pair<int, int> new_val) {
  if(dp[idx].second == -1) {
	dp[idx] = new_val;
	return;
  }

  if(dp[idx].first > new_val.first) dp[idx] = new_val;
}

int get_or_fill_dp(int idx) {
  if(dp[idx].second != -1) return dp[idx].first;

  if(idx == 1) {
	dp[idx] = make_pair(0, 0);
	return dp[idx].first;
  }

  if(idx % 3 == 0) fill_dp(idx, make_pair(get_or_fill_dp(idx / 3) + 1, 3));
  if(idx % 2 == 0) fill_dp(idx, make_pair(get_or_fill_dp(idx / 2) + 1, 2)); 
  fill_dp(idx, make_pair(get_or_fill_dp(idx - 1) + 1, 1));

  return dp[idx].first;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  init_dp();

  int res = get_or_fill_dp(n);
  cout << res << "\n";

  while(dp[n].second != 0) {
	cout << n << " ";
	if(dp[n].second == 1) n = n - dp[n].second;
	else n = n / dp[n].second;
  }
  cout << "1\n";
  return 0;
}
