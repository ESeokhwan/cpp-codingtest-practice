#include "bits/stdc++.h"
using namespace std;

int debug = 0;

int R, C, K, W;

// 0: (x, y) | (x-1, y) / 1: (x, y) | (x, y+1)
bool walls[23][23][2];

vector<pair<int, int> > target_points;
vector<pair<int, pair<int, int> > > vacums;

int _map[23][23];
int dirs[4][3][2] = { 
  { {0, 1}, {1, 1}, {-1, 1} },
  { {0, -1}, {1, -1}, {-1, -1} },
  { {-1, 0}, {-1, 1}, {-1, -1} },
  { {1, 0}, {1, 1}, {1, -1} }
};

int res = 0;

bool can_go(int x, int y, int nx, int ny, int st_d) {
  // 하나만 다름
  if ((x == nx && y != ny) || (x != nx && y == ny)) {
	if (x != nx && y == ny && walls[max(x, nx)][y][0] == true) return false;
	if (x == nx && y != ny && walls[x][min(y, ny)][1] == true) return false;
	return true;
  }
  
  // 둘 다 다름
  if (st_d == 0 || st_d == 1) {
	if (walls[max(x, nx)][y][0] == true) return false;
	if (walls[nx][min(y, ny)][1] == true) return false;
	return true;
  }

  if (st_d == 2 || st_d == 3) {
	if (walls[x][min(y, ny)][1] == true) return false;
	if (walls[max(x, nx)][ny][0] == true) return false;
	return true;
  }
  return true;
}

void exec_vacum(int st_r, int st_c, int st_d) {
  queue<pair<int, int> > q;
  int visited[23][23];
  memset(visited, 0, sizeof(visited));

  int r_st_r = st_r + dirs[st_d][0][0];
  int r_st_c = st_c + dirs[st_d][0][1];
  if (r_st_r < 0 || r_st_r >= R || r_st_c < 0 || r_st_c >= C) return;
  q.push({ r_st_r, r_st_c });
  visited[r_st_r][r_st_c] = 1;
  while(!q.empty()) {
	int cur_r = q.front().first;
	int cur_c = q.front().second;
	q.pop();
	if (dirs[st_d][0][0] != 0) {
	  _map[cur_r][cur_c] += (5 - abs(cur_r - r_st_r));
	} else {
	  _map[cur_r][cur_c] += (5 - abs(cur_c - r_st_c));
	}

	for(auto dir: dirs[st_d]) {
	  int nx_r = cur_r + dir[0];
	  int nx_c = cur_c + dir[1];

	  if (nx_r < 0 || nx_r >= R || nx_c < 0 || nx_c >= C) continue;
	  if (visited[nx_r][nx_c] == 1) continue;
	  if (!can_go(cur_r, cur_c, nx_r, nx_c, st_d)) continue;

	  if ((dirs[st_d][0][0] != 0 && abs(nx_r - st_r) > abs(dirs[st_d][0][0] * 5)) ||
		  (dirs[st_d][0][1] != 0 && abs(nx_c - st_c) > abs(dirs[st_d][0][1] * 5))
	  ) continue;
	  q.push({ nx_r, nx_c });
	  visited[nx_r][nx_c] = 1;
	}
  }
}

void mod_c() {
  int new_map[23][23];
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  new_map[i][j] = _map[i][j];
	}
  }
 
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  if (i < R - 1 && walls[i + 1][j][0] == false) {
	    int diff_r = _map[i][j] - _map[i + 1][j];
	    new_map[i][j] -= (diff_r / 4);
	    new_map[i + 1][j] += (diff_r / 4);
	  }
	  
	  if (j < C - 1 && walls[i][j][1] == false) {
		int diff_c = _map[i][j] - _map[i][j + 1];
		new_map[i][j] -= (diff_c / 4);
		new_map[i][j + 1] += (diff_c / 4);
	  }
	}
  }
  
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  _map[i][j] = new_map[i][j];
	}
  }

}

void reduce_c() {
  for (int i = 0; i < R; i++) {
	_map[i][0] = max(0, _map[i][0] - 1);
	_map[i][C - 1] = max(0, _map[i][C - 1] - 1);
  }
  
  for (int i = 1; i < C - 1; i++) {
	_map[0][i] = max(0, _map[0][i] - 1);
	_map[R - 1][i] = max(0, _map[R - 1][i] - 1);
  }
}

bool check() {
  for (auto tp : target_points) {
	if (_map[tp.first][tp.second] < K) return false;
  }
  return true;
}

void print() {
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  char wall = ' ';
	  if (walls[i][j][1] == true) wall = '|';
	  cout << _map[i][j] << wall;
	}
	cout << "\n";
	if (i == R - 1) continue;
	for (int j = 0; j < C; j++) {
	  char wall = ' ';
	  if (walls[i + 1][j][0] == true) wall = '-';
	  cout << wall << " ";
	}
	cout << "\n";
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C >> K;
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  int input;
	  cin >> input;
	  if (input == 0) continue;
	  if (input == 5) target_points.push_back({ i, j });
	  else vacums.push_back({ input - 1, { i, j } });
	}
  }

  memset(_map, 0, sizeof(_map));
  memset(walls, false, sizeof(walls));
  cin >> W;
  for (int i = 0; i < W; i++) {
	int input1, input2, input3;
	cin >> input1 >> input2 >> input3;
	walls[input1 - 1][input2 - 1][input3] = true;
  }

  res = 0;
  while (!check()) {
	if (debug == 1) {
	  cout << "==========================================\n";
	}
    for (auto vacum: vacums) {
	  exec_vacum(vacum.second.first, vacum.second.second, vacum.first);
	  if (debug == 1) {
	    cout << "VACUM\n";
  	    print();
	    cout << "\n";
	  }
    }
    mod_c();
	if (debug == 1) {
	  cout << "MOD\n";
	  print();
	  cout << "\n";
	}
    reduce_c();
	if (debug == 1) {
	  cout << "REDUCE\n";
 	  print();
	  cout << "\n";
	}
	res += 1;
	if (res > 100) break;
  }

  cout << res << "\n";
  return 0;
}
