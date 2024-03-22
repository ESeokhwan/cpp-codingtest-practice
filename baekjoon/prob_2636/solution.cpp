#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int board[105][105];

pair<int, int> dirs[4] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int bfs() {
  queue<pair<int, int > > q;
  int visited[105][105];
  memset(visited, 0, sizeof(visited));

  q.push({0, 0});
  visited[0][0] = 1;

  int d_cnt = 0;
  while(!q.empty()) {
	int cr = q.front().first;
	int cc = q.front().second;
	q.pop();

	for (auto dir: dirs) {
	  int nr = cr + dir.first;
	  int nc = cc + dir.second;
	  if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
	  if (visited[nr][nc] == 1) continue;
	  if (board[nr][nc] == 0) {
		q.push({ nr, nc });
		visited[nr][nc] = 1;
	  } else {
		visited[nr][nc] = 1;
		board[nr][nc] = 0;
		d_cnt += 1;
	  }
	}
  }
  return d_cnt;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  cin >> board[i][j];
	}
  }

  int prev = 0;
  int cnt = 0;
  while(true) {
	int tmp = bfs();
	if (tmp == 0) break;
	prev = tmp;
	cnt += 1;
  }

  cout << cnt << "\n";
  cout << prev << "\n";
  return 0;
}
