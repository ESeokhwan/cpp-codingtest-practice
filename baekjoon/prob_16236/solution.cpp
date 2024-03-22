#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];
int dist[20][20];

pair<int, int> sh;
int sh_sz;
int sh_cnt;

pair<int, int> dirs[4] = {{1,0},{-1,0},{0,1},{0,-1}};

void calc_dist() {
  queue<pair<pair<int, int>, int > > q;
  memset(dist, -1, sizeof(dist));

  q.push({ sh, 0 });
  dist[sh.first][sh.second] = 0;
  while (!q.empty()) {
	int cr = q.front().first.first;
	int cc = q.front().first.second;
	int cd = q.front().second;
	q.pop();

	for (auto dir : dirs) {
	  int nr = cr + dir.first;
	  int nc = cc + dir.second;
	  int nd = cd + 1;
	  if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
	  if (dist[nr][nc] != - 1) continue;
	  if (board[nr][nc] > sh_sz) continue;
	  q.push({ { nr, nc }, nd });
	  dist[nr][nc] = nd;
	}
  }
}

pair<int, int> check_near() {
  int min_d = 10000000;
  pair<int, int> output = { -1, -1 };
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  if (dist[i][j] <= 0) continue;
	  if (dist[i][j] < min_d && board[i][j] < sh_sz && board[i][j] != 0) {
		output = { i, j };
		min_d = dist[i][j];
	  }
	}
  }
  return output;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  cin >> board[i][j];
	  if (board[i][j] == 9) {
		sh = { i, j };
		board[i][j] = 0;
	  }
	}
  }
  
  int cnt = 0;
  sh_sz = 2;
  sh_cnt = 0;
  while(true) {
	calc_dist();
	pair<int, int> target = check_near();
	if (target.first == -1) break;
	sh = target;
	cnt += dist[target.first][target.second];
	
	sh_cnt += 1;
	if (sh_cnt == sh_sz) {
	  sh_cnt = 0;
	  sh_sz += 1;
	}
	board[target.first][target.second] = 0;
  }

  cout << cnt << "\n";
  return 0;
}
