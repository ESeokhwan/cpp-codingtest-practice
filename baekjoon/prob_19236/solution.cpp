#include <bits/stdc++.h>

using namespace std;

pair<int, int> _map[4][4];

pair<int, int> fish_pos[16];
int res;

pair<int, int> shark_pos;

pair<int, int> dirs[8] = {
  make_pair(-1, 0),
  make_pair(-1, -1),
  make_pair(0, -1),
  make_pair(1, -1),
  make_pair(1, 0),
  make_pair(1, 1),
  make_pair(0, 1),
  make_pair(-1, 1)
};

void make_fish_pos() {
  for(int i = 0; i < 16; i++) fish_pos[i] = make_pair(-1, -1);
  
  for(int i = 0; i < 4; i++) {
	for(int j = 0; j < 4; j++) {
	  int f_num = _map[i][j].first;
	  if(f_num == -1) continue;

	  if(f_num == 16) shark_pos = make_pair(i, j);
	  else fish_pos[f_num] = make_pair(i, j);
	}
  }
}

void set_map(pair<int, int> new_map[4][4]) {
  for(int i = 0; i < 4; i++) {
	for(int j = 0; j < 4; j++) {
	  _map[i][j].first = new_map[i][j].first;
	  _map[i][j].second = new_map[i][j].second;
	}
  }

  make_fish_pos();
}

void move_fish() {
  for(int i = 0; i < 16; i++) {
	int cur_r = fish_pos[i].first;
	int cur_c = fish_pos[i].second;
	if(fish_pos[i].first == -1) continue;
	
	int cur_d = _map[cur_r][cur_c].second;
	for(int j = 0; j < 8; j++) {
	  int nr = cur_r + dirs[cur_d].first;
	  int nc = cur_c + dirs[cur_d].second;
	  if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) {
		cur_d = (cur_d + 1) % 8;
		continue;
	  }
	  if(_map[nr][nc].first == 16) {
		cur_d = (cur_d + 1) % 8;
		continue;
	  }
	  
	  pair<int, int> tar = _map[nr][nc];
	  _map[cur_r][cur_c] = tar;
	  _map[nr][nc].first = i;
	  _map[nr][nc].second = cur_d;

	  if(tar.first != -1) fish_pos[tar.first] = fish_pos[i];
	  fish_pos[i] = make_pair(nr, nc);
	  break;
	}
  }
}

int move_shark(int acc, int v) {
  int shark_dir = _map[shark_pos.first][shark_pos.second].second;
  int nr = shark_pos.first + v * dirs[shark_dir].first;
  int nc = shark_pos.second + v * dirs[shark_dir].second;
  if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) return -1;
  
  int tar = _map[nr][nc].first;
  if(tar == -1) return -1;

  fish_pos[tar] = make_pair(-1, -1);
  _map[shark_pos.first][shark_pos.second] = make_pair(-1, -1);
  _map[nr][nc] = make_pair(16, _map[nr][nc].second);
  return acc + tar + 1;
}

void dfs(int acc, pair<int, int> l_map[4][4]) {
  pair<int, int> tmp_map[4][4];
  for(int j = 0; j < 4; j++) {
	for(int k = 0; k < 4; k++) {
	  tmp_map[j][k].first = l_map[j][k].first;
	  tmp_map[j][k].second = l_map[j][k].second;
	}
  }
  for(int i = 1; i < 4; i++) {
	
	set_map(tmp_map);
	move_fish();
	int new_acc = move_shark(acc, i);
	if(new_acc != -1) dfs(new_acc, _map);
	else res = max(res, acc);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 4; i++) {
	for(int j = 0; j < 4; j++) {
	  cin >> _map[i][j].first >> _map[i][j].second;
	  _map[i][j].first -= 1;
	  _map[i][j].second -= 1;
	}
  }

  res = _map[0][0].first + 1;
  _map[0][0].first = 16;

  dfs(res, _map);
  cout << res << "\n";
  return 0;
}
