#include <bits/stdc++.h>
using namespace std;

int r, c;
int total_cnt;
char _map[25][25];
int visited[25][25];
pair<int, int> st, en;
pair<int, int> dirs[4] = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
char blocks[7] = { '-', '|', '+', '1', '2', '3', '4' };

bool simulate(pair<int, int> pos, char new_block) {
  memset(visited, false, sizeof(visited));
 
  int cur_r, cur_c, cur_dir, cur_cnt;
  for(int i = 0; i < 4; i++) {
	int next_r = st.first + dirs[i].first;
	int next_c = st.second + dirs[i].second;
	if(next_r < 0 || next_r >= r || next_c < 0 || next_c >= c) continue;
	if(_map[next_r][next_c] == '.' || _map[next_r][next_c] == 'Z') continue;
	cur_r = next_r;
	cur_c = next_c;
	cur_dir = i;
	cur_cnt = 1;
	visited[cur_r][cur_c] = true;
  }

  while(true) {
	char cur_block = _map[cur_r][cur_c];
	if(cur_block == 'Z') {
	  if(cur_cnt == total_cnt + 1) return true;
	  return false;
	}
	
	if(pos.first == cur_r && pos.second == cur_c) cur_block = new_block;
	if(cur_block == '.') return false;
	
	int next_r, next_c, next_dir;
	if((cur_block == '-' && (cur_dir == 0 || cur_dir == 2))
		|| (cur_block == '|' && (cur_dir == 1 || cur_dir == 3)) 
		|| cur_block == '+') {
	  next_dir = cur_dir;
	} else if(cur_block == '1' && cur_dir == 0) {
	  next_dir = 1;
	} else if(cur_block == '1' && cur_dir == 3) {
	  next_dir = 2;
	} else if(cur_block == '2' && cur_dir == 1) {
	  next_dir = 2;
	} else if(cur_block == '2' && cur_dir == 0) {
	  next_dir = 3;
	} else if(cur_block == '3' && cur_dir == 2) {
	  next_dir = 3;
	} else if(cur_block == '3' && cur_dir == 1) {
	  next_dir = 0;
	} else if(cur_block == '4' && cur_dir == 3) {
	  next_dir = 0;
	} else if(cur_block == '4' && cur_dir == 2) {
	  next_dir = 1;
	} else {
	  return false;
	}

	next_r = cur_r + dirs[next_dir].first;
	next_c = cur_c + dirs[next_dir].second;
	if(next_r < 0 || next_r >= r || next_c < 0 || next_c >= c) return false;
	if(!visited[next_r][next_c]) cur_cnt += 1;
	cur_r = next_r;
	cur_c = next_c;
	cur_dir = next_dir;
	visited[cur_r][cur_c] = true;
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> r >> c;
  total_cnt = 0;
  for(int i = 0; i < r; i++) {
	for(int j = 0; j < c; j++) {
	  cin >> _map[i][j];
	  if(_map[i][j] == 'M') st = { i, j };
	  else if(_map[i][j] == 'Z') en = { i, j };
	  else if(_map[i][j] != '.') total_cnt += 1;
	}
  }
  total_cnt += 1;

  pair<int, int> res_pos;
  char res_block;
  for(int i = 0; i < r; i++) {
	for(int j = 0; j < c; j++) {
	  if(_map[i][j] != '.') continue;
	  for(auto block: blocks) {
		if(simulate({ i, j }, block)) {
		  cout << i + 1 << " " << j + 1 << " " << block << "\n";
		  return 0;
		}
	  }
	}
  }

  return 0;
}
