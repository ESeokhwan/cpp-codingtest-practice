#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int dp[4][100001];

bool is_updated;

void update_dp_value(int idx1, int idx2, int new_value) {
  if(dp[idx1][idx2] == -1 || dp[idx1][idx2] > new_value) {
	dp[idx1][idx2] = new_value;
	is_updated = true;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> a >> b >> c >> d;

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  dp[1][0] = 1;
  dp[2][0] = 0;
  dp[3][0] = 1;

  dp[2][a] = 1;
  dp[0][b] = 1;
  dp[3][a] = 2;
  dp[1][b] = 2;

  bool is_end;
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
	int cur = q.front();
	q.pop();

	if(cur > b) continue;
	
	is_updated = false;
	if(cur + a > b) {
	  update_dp_value(3, a+cur-b, dp[1][cur] + 1);
	  update_dp_value(2, a+cur-b, dp[1][cur] + 2);
	  update_dp_value(0, a+cur-b, dp[1][cur] + 3);
	  update_dp_value(1, a+cur-b, dp[1][cur] + 4);
	  if(is_updated) q.push(a+cur-b);
	} else {
	  update_dp_value(0, a+cur, dp[1][cur] + 1);
	  update_dp_value(1, a+cur, dp[1][cur] + 2);
	  if(is_updated) q.push(a+cur);
	}

	is_updated = false;
	if(cur > a) {
	  update_dp_value(1, cur-a, dp[0][cur] + 1);
	  update_dp_value(0, cur-a, dp[0][cur] + 2);
	  update_dp_value(2, cur-a, dp[0][cur] + 3);
	  update_dp_value(3, cur-a, dp[0][cur] + 4);
	  if(is_updated) q.push(cur-a);
	  continue;
	}

	is_updated = false;
	update_dp_value(1, b+cur-a, dp[3][cur] + 1);
	update_dp_value(0, b+cur-a, dp[3][cur] + 2);
	if(b+cur-a < a) {
	  update_dp_value(2, b+cur-a, dp[3][cur] + 3);
	  update_dp_value(3, b+cur-a, dp[3][cur] + 4);
	}
	if(is_updated) q.push(b+cur-a);
  }
  
  if(c == 0) {
	cout << dp[0][d] << "\n";
  } else if(c == a) {
	cout << dp[1][d] << "\n";
  } else if(d == 0) {
	cout << dp[2][c] << "\n";
  } else if(d == b) {
	cout << dp[3][c] << "\n";
  } else {
	cout << -1 <<  "\n";
  }
  
  return 0;
}
