#include <bits/stdc++.h>
using namespace std;

string input;
int cr[5000];
int dp[5000];

int fill_dp(int idx) {
  if(idx < 0) return 1;
  if(dp[idx] != -1) return dp[idx];

  if(idx == 0) {
	if(cr[idx] == 0) dp[idx] = 0;
	else dp[idx] = 1;
	return dp[idx];
  }
  
  int res = 0;
  if(cr[idx] == 0) {
	if(cr[idx-1] == 1 || cr[idx-1] == 2) res = fill_dp(idx-2);
	else res = 0;
  } else if(cr[idx-1] == 1 || (cr[idx-1] == 2 && cr[idx] <= 6)) {
	int tmp1 = fill_dp(idx-2);
	int tmp2 = fill_dp(idx-1);
	if(tmp1 == 0 || tmp2 == 0) res = 0;
	else res = (tmp1 + tmp2) % 1000000;
  } else {
	res = fill_dp(idx-1);
  }
  dp[idx] = res;
  return dp[idx];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> input;

  for(int i = 0; i < input.length(); i++) {
	if(input[i] >= '0' && input[i] <= '9') cr[i] = (int) (input[i] - '0');
	else {
	  cout << 0 << "\n";
	  return 0;
	}
  }

  cout << fill_dp(input.length()- 1);
  cout << "\n";

  return 0;
}
