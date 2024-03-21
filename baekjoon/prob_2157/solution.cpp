#include <bits/stdc++.h>

using namespace std;

int n, m, k;
map<int, int> route[301];

int dp[301][301];

int gofd(int en, int cnt) {
  if (dp[en][cnt] != -1) return dp[en][cnt];
  if (en == 1 || cnt == 0) {
	dp[en][cnt] = 0;
	return dp[en][cnt];
  }
  
  int sub_res = 0;
  for (int i = 1; i < en; i++) {
	map<int,int>::iterator it = route[i].find(en);
	if (it == route[i].end()) continue;
	if (i != 1 && gofd(i, cnt - 1) == 0) continue;
	sub_res = max(sub_res, gofd(i, cnt - 1) + (it -> second));
  }
  dp[en][cnt] = sub_res;
  return dp[en][cnt];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
	int st, en, val;
	cin >> st >> en >> val;
	if (st >= en) continue;
	map<int,int>::iterator it = route[st].find(en);
	if (it == route[st].end() || (it -> second) < val) route[st][en] = val;
  }
  
  cout << gofd(n, m - 1) << "\n";
  return 0;
}
