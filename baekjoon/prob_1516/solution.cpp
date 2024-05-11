#include "bits/stdc++.h"
using namespace std;

int n;
int dp[500];

int build_t[500];
vector<int> prev_build[500];

int gofd(int x) {
  if (dp[x] != -1) return dp[x];

  dp[x] = build_t[x];

  int max_prev = 0;
  for (int i = 0; i < prev_build[x].size(); i++) {
	max_prev = max(max_prev, gofd(prev_build[x][i]));
  }
  dp[x] += max_prev;
  return dp[x];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  int tmp;
  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> build_t[i];
	while (1) {
	  cin >> tmp;
	  if (tmp == -1) break;
	  prev_build[i].push_back(tmp - 1);
	}
  }

  for (int i = 0; i < n; i++) {
	cout << gofd(i) << "\n";
  }
  return 0;
}
