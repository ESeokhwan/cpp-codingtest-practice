#include <bits/stdc++.h>
using namespace std;

int n, m;
int _map[1000][1000];
int dp1[1000][1000];
int dp2[1000][1000];

int gofd1(int r, int c) {
  if(dp1[r][c] != -1) return dp1[r][c];
  
  if(r == n - 1 && c == 0) dp1[r][c] = _map[r][c];
  else if(r == n - 1) dp1[r][c] = gofd1(r, c - 1) + _map[r][c];
  else if(c == 0) dp1[r][c] = gofd1(r + 1, c) + _map[r][c];
  else dp1[r][c] = max(gofd1(r + 1, c), gofd1(r, c - 1)) + _map[r][c];
  return dp1[r][c];
}

int gofd2(int r, int c) {
  if(dp2[r][c] != -1) return dp2[r][c];
  
  if(r == n - 1 && c == m - 1) dp2[r][c] = _map[r][c];
  else if(r == n - 1) dp2[r][c] = gofd2(r, c + 1) + _map[r][c];
  else if(c == m - 1) dp2[r][c] = gofd2(r + 1, c) + _map[r][c];
  else dp2[r][c] = max(gofd2(r + 1, c), gofd2(r, c + 1)) + _map[r][c];
  return dp2[r][c];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) cin >> _map[i][j];
  }
  gofd1(0, m - 1);
  gofd2(0, 0);

  int res = -1000000000;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  res = max(res, dp1[i][j] + dp2[i][j]);
	}
  }

  cout << res << "\n";
  return 0;
}
