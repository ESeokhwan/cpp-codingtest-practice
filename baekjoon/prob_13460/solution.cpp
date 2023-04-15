#include <bits/stdc++.h>
using namespace std;

int n, m;
int _map[10][10];
int cnt = 0;
int res = 100;
pair<int, int> c_pos[2];

pair<int, int> dirs[4] = {
  make_pair(1, 0),
  make_pair(0, 1),
  make_pair(-1, 0),
  make_pair(0, -1)
};

int move(int dir) {
  bool reverse = false;
  if(dir == 0 && c_pos[0].first < c_pos[1].first) reverse = true;
  if(dir == 1 && c_pos[0].second < c_pos[1].second) reverse = true;
  if(dir == 2 && c_pos[0].first > c_pos[1].first) reverse = true;
  if(dir == 3 && c_pos[0].second > c_pos[1].second) reverse = true;

  int output[2];
  output[0] = 0;
  output[1] = 0;
  int st = 0;
  if(reverse) st = 1;
  for(int i = 0; i < 2; i++) {
	int cur_r = c_pos[(st + i) % 2].first;
	int cur_c = c_pos[(st + i) % 2].second;
	
	for(int j = 0; j < 10; j++) {
	  c_pos[(st + i) % 2] = make_pair(cur_r, cur_c);
	  cur_r += dirs[dir].first;
	  cur_c += dirs[dir].second;
	  if(i == 1 && cur_r == c_pos[st].first && cur_c == c_pos[st].second) break;
	  if(_map[cur_r][cur_c] == '#') break;
	  if(_map[cur_r][cur_c] == 'O') {
		if((st + i) % 2 == 0) {
		  output[(st + i)%2] = 1;
		  c_pos[(st + i) % 2] = make_pair(-1, -1);
		  break;
		}
		return -1;
	  }
	}
  }
  if(output[0] == 1) return 1;
  return 0;
}

void dfs(int cnt) {
  if(cnt > 10) return;

  for(int i = 0; i < 4; i++) {
	pair<int, int> tmp1 = c_pos[0];
	pair<int, int> tmp2 = c_pos[1];
	int re = move(i);
	if(re == 0) dfs(cnt + 1);
	else if(re == 1) {
	  res = min(res, cnt + 1);
	}
	c_pos[0] = tmp1;
	c_pos[1] = tmp2;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	string input;
	cin >> input;
	for(int j = 0; j < m; j++) {
	  _map[i][j] = input[j];
	  if(_map[i][j] == 'R') c_pos[0] = make_pair(i, j);
	  if(_map[i][j] == 'B') c_pos[1] = make_pair(i, j);
	}
  }
  
  dfs(0);
  if(res > 10) cout << "-1\n";
  else cout << res << "\n";
  return 0;
}
