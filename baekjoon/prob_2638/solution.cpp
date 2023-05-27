#include <bits/stdc++.h>
using namespace std;

int n, m;
int _map[100][100];
int visited[100][100];

pair<int, int> dirs[4] = {
  make_pair(1, 0),
  make_pair(0, 1),
  make_pair(-1, 0),
  make_pair(0, -1)
};

bool check_cheese(int r, int c) {
  if(_map[r][c] != 1) return false;
  int cnt = 0;
  for(auto dir: dirs) {
	int nr = r + dir.first;
	int nc = c + dir.second;
	if(nr < 0 || nr >= n || nc < 0 || nc >= m) cnt += 1;
	if(_map[nr][nc] == -1) cnt += 1;
  }
  return cnt >= 2;
}
	

void set_outside() {
  memset(visited, false, sizeof(visited));

  pair<int, int> sp = make_pair(0,0);
  queue<pair<int, int> > q;
  q.push(sp);
  visited[0][0] = true;
  while(!q.empty()) {
	int cr = q.front().first;
	int cc = q.front().second;
	q.pop();
	_map[cr][cc] = -1;
	
	for(auto dir : dirs) {
	  int nr = cr + dir.first;
	  int nc = cc + dir.second;
	  if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
	  if(visited[nr][nc]) continue;
	  if(_map[nr][nc] == 1) continue;
	  q.push(make_pair(nr, nc));
	  visited[nr][nc] = true;
	}
  }
}

bool reduce_cheese() {
  bool cheese_reduced = false;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) { 
	  if(check_cheese(i, j)) {
		_map[i][j] = 0;
		cheese_reduced = true;
	  }	
	}
  }
  return cheese_reduced;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  cin >> _map[i][j];
	}
  }

  int res = 0;
  bool flag = true;
  while(flag) {
	set_outside();
	flag = reduce_cheese();
	res += 1;
  }

  cout << res - 1 << "\n";
  return 0;
}
