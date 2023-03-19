#include <bits/stdc++.h>
using namespace std;

int n, m, k, t;

int st[305];
int en[305];

int up_timing[305][305];
int dp[305][305];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(st, 0, sizeof(st));
  memset(en, 0, sizeof(en));

  cin >> n >> m >> k >> t;

  for(int i = 0; i < m; i++) {
	int input[2];
	cin >> input[0] >> input[1];
	st[input[0]]++;
	en[input[1]]++;
  }

  int cnt = 1;
  int cur_pf = 0;
  int prev_pf = 0;
  int lv = 0;
  int acc = 0;
  for(int i = 1; i <= n; i++) {
	cur_pf += st[i];
	cur_pf -= en[i];
	if(cur_pf < t) {
	  up_timing[cnt][t-cur_pf]++;
	  lv = max(lv, t-cur_pf);
	} else {
	  acc++;
	  if(prev_pf < t) {
		for(int i = 1; i <= lv; i++) up_timing[cnt][i] += up_timing[cnt][i-1];
		up_timing[cnt][lv + 1] = -1;
		cnt++;
		lv = 0;
	  }
	}
	prev_pf = cur_pf;
  }
  for(int i = 1; i <= lv; i++) up_timing[cnt][i] += up_timing[cnt][i-1];
  up_timing[cnt][lv + 1] = -1;

  for(int i = 1; i <= cnt; i++) {
	for(int j = 0; up_timing[i][j] != -1; j++) {
	  for(int l = 0; l <= k - j; l++) {
		dp[i][l + j] = max(dp[i][l + j], dp[i-1][l] + up_timing[i][j]);
	  }
	}
  }
  
  cout << dp[cnt][k] + acc << "\n";
  return 0;
}
