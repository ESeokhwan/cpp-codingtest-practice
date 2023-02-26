#include <bits/stdc++.h>
using namespace std;

int n, m;
bool dp[2005][2005];

int nums[2000];
int s_e[1000000][2];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < n; i++) memset(dp[i], false, sizeof(bool)*n);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> nums[i];
  
  cin >> m;
  for(int i = 0; i < m; i++) cin >> s_e[i][0] >> s_e[i][1];

  for(int i = 0; i < n; i++) {
	dp[i][i] = true;
	if(nums[i] == nums[i+1]) dp[i][i+1] = true;
  }

  for(int i = 2; i < n; i++) {
	for(int j = 0; j < n-i; j++) {
	  if(dp[j+1][j+i-1] && nums[j] == nums[j+i]) dp[j][j+i] = true;
	}
  }

  for(int i = 0; i < m; i++) cout << dp[s_e[i][0]-1][s_e[i][1]-1] << "\n";
  cout << "\n";
  return 0;
}
