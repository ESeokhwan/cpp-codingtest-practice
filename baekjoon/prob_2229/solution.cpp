#include <bits/stdc++.h>
using namespace std;

int MAX_INT = 987654321;

int n;
int scores[1005];

int min_dp[1005][1005];
int max_dp[1005][1005];
int dp[1005];

int gofd_min(int st, int en) {
  if (min_dp[st][en] != -1) return min_dp[st][en];
  if (st == en) {
	min_dp[st][en] = scores[st];
  } else if (st > en) {
	min_dp[st][en] = MAX_INT;
  } else {
	min_dp[st][en] = min(gofd_min(st, en - 1), scores[en]);
  }
  return min_dp[st][en];
}

int gofd_max(int st, int en) {
  if (max_dp[st][en] != -1) return max_dp[st][en];
  if (st == en) {
	max_dp[st][en] = scores[st];
  } else if (st > en) {
	max_dp[st][en] = 0;
  } else {
	max_dp[st][en] = max(gofd_max(st, en - 1), scores[en]);
  }
  return max_dp[st][en];
}

int gofd(int idx) {
  if (dp[idx] != -1) {
	return dp[idx];
  }

  if (idx == 0) {
	dp[idx] = 0;
  } else {
	int sub_res = 0;
	for (int i = 0; i < idx; i++) {
	  int tmp_res = gofd(i) + gofd_max(i, idx - 1) - gofd_min(i, idx - 1);
	  sub_res = max(sub_res, tmp_res);
	}
	dp[idx] = sub_res;
  }
  return dp[idx];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> scores[i];
  }
  memset(dp, -1, sizeof(dp));
  memset(min_dp, -1, sizeof(min_dp));
  memset(max_dp, -1, sizeof(max_dp));

  cout << gofd(n) << "\n";
  return 0;
}
