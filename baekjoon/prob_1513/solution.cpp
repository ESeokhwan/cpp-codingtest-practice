#include <bits/stdc++.h>
using namespace std;

int n, m, c;

bool visited[50][50];
int c_map[50][50];
int dp[50][50][51][51];

pair<int, int> offsets[2] = {
  make_pair(0, 1),
  make_pair(1, 0)
};

void init_dp() {
  if(c_map[0][0] == 0) dp[0][0][0][0] = 1;
  else dp[0][0][1][c_map[0][0]] = 1;
}

void bfs_map() {
  queue< pair< int, int > > q;
  q.push(make_pair(0, 0));
  visited[0][0] = true;
  while(!q.empty()) {
	int cur_r = q.front().first;
	int cur_c = q.front().second;
	q.pop();

	for(pair<int, int> off : offsets) {
	  int nr = cur_r + off.first;
	  int nc = cur_c + off.second;
	  int n_info = c_map[nr][nc];
	  if(nr == n || nc == m) continue;
	  for(int i = 0; i < c + 1; i++) {
		for(int j = i; j < c + 1; j++) {
		  if(n_info == 0) dp[nr][nc][i][j] = (dp[nr][nc][i][j] + dp[cur_r][cur_c][i][j]) % 1000007;
		  else if(n_info > j) dp[nr][nc][i+1][n_info] = (dp[nr][nc][i+1][n_info] + dp[cur_r][cur_c][i][j]) % 1000007;
		}
	  }
	  if(visited[nr][nc]) continue;
	  q.push(make_pair(nr, nc));
	  visited[nr][nc] = true;
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(visited, false, sizeof(visited));
  memset(c_map, 0, sizeof(c_map));
  memset(dp, 0, sizeof(dp));

  cin >> n >> m >> c;
  for(int i = 0; i < c; i++) {
	int cur_r, cur_c;
	cin >> cur_r >> cur_c;
	c_map[cur_r - 1][cur_c - 1] = i+1;
  }
  init_dp();
  bfs_map();
  for(int i = 0; i < c+1; i++) {
	int res = 0;
	for(int j = i; j < c+1; j++) {
	  res = (res + dp[n-1][m-1][i][j]) % 1000007;
	}
	cout << res << " ";
  }
  cout << "\n";
  return 0;
}
