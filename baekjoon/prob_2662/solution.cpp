#include <bits/stdc++.h>
using namespace std;

int n, m;
int score[301][21];
int dp[301][21];
vector<int> dp2[301][21];

int gofd(int m_limit, int c_limit) {
  if(dp[m_limit][c_limit] != -1) return dp[m_limit][c_limit];

  if(c_limit == 1) {
	if(m_limit == 0) {
	  dp[m_limit][c_limit] = 0;
	  dp2[m_limit][c_limit].push_back(0);
	} else {
	  dp[m_limit][c_limit] = score[m_limit][c_limit];
	  dp2[m_limit][c_limit].push_back(m_limit);
	}
  } else {
	int tmp_max = -1;
	int max_idx = -1;
	for(int i = 0; i <= m_limit; i++) {
	  int cur_score = gofd(i, c_limit - 1) + score[m_limit - i][c_limit];
	  if(tmp_max > cur_score) continue;
	  tmp_max = cur_score;
	  max_idx = i;
	}
	dp[m_limit][c_limit] = tmp_max;
	dp2[m_limit][c_limit].clear();
	for(int i = 0; i < dp2[max_idx][c_limit - 1].size(); i++) {
	  dp2[m_limit][c_limit].push_back(dp2[max_idx][c_limit - 1][i]);
	}
	dp2[m_limit][c_limit].push_back(m_limit - max_idx);
  }
  return dp[m_limit][c_limit];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
	int trash;
	cin >> trash;
	for(int j = 1; j <= m; j++) cin >> score[i][j];
  }

  for(int i = n; i >= 0; i--) gofd(i, m);

  int res_idx;
  int res = -1;
  for(int i = 1; i <= n; i++) {
	if(res > dp[i][m]) continue;
	res = dp[i][m];
	res_idx = i;
  }
  cout << res << "\n";
  for(int i = 0; i < dp2[res_idx][m].size(); i++) {
	cout << dp2[res_idx][m][i] << " ";
  }
  cout << "\n";

  return 0;
}
