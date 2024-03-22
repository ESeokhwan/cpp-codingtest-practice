#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[8][8];

pair<int, int> dirs[4] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int bfs() {
  int tmp_board[8][8];
  vector<pair<int, int> > viruses;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  if (board[i][j] == 2) viruses.push_back({ i, j });
	  tmp_board[i][j] = board[i][j];
	}
  }

  queue<pair<int, int > > q;
  int visited[8][8];
  memset(visited, 0, sizeof(visited));
  for(auto virus: viruses) {
	q.push(virus);
	visited[virus.first][virus.second] = 1;
  }
  while (!q.empty()) {
	int cr = q.front().first;
	int cc = q.front().second;
	q.pop();
	
	for (auto dir: dirs) {
	  int nr = cr + dir.first;
	  int nc = cc + dir.second;
	  if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
	  if (visited[nr][nc] == 1) continue;
	  if (tmp_board[nr][nc] != 1) {
		tmp_board[nr][nc] = 2;
		visited[nr][nc] = 1;
		q.push({nr, nc});
	  }
	}
  }
  
  int cnt = 0;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	  if (tmp_board[i][j] == 0) cnt += 1;
	}
  }
  return cnt;
}

int rec(pair<int, int> x1, pair<int, int> x2, pair<int, int> x3) {
  if (x1.first >= n) return 0;
  if (x1.second >= m) return rec({ x1.first + 1, 0 }, x2, x3);
  if (x2.first >= n) return rec({ x1.first, x1.second + 1 }, { 0, 0 }, { 0, 0 });
  if (x2.second >= m) return rec(x1, { x2.first + 1, 0 }, x3);
  if (x3.first >= n) return rec(x1, { x2.first, x2.second + 1 }, { 0, 0 });
  if (x3.second >= m) return rec(x1, x2, { x3.first + 1, 0 });
  if ((x1.first == x2.first && x1.second == x2.second)
	  || (x1.first == x3.first && x1.second == x3.second)
	  || (x2.first == x3.first && x2.second == x3.second)) {
	return rec(x1, x2, { x3.first, x3.second + 1 });
  }


  if (board[x1.first][x1.second] != 0 
	  || board[x2.first][x2.second] != 0 
	  || board[x3.first][x3.second] != 0) {
	return rec(x1, x2, { x3.first, x3.second + 1 });
  }

  board[x1.first][x1.second] = 1;
  board[x2.first][x2.second] = 1;
  board[x3.first][x3.second] = 1;
  int new_res = bfs();
  board[x1.first][x1.second] = 0;
  board[x2.first][x2.second] = 0;
  board[x3.first][x3.second] = 0;

  return max(new_res, rec(x1, x2, { x3.first, x3.second + 1 }));
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

  cout << rec({0, 0}, {0, 1}, {0, 2}) << "\n";
  return 0;
}
