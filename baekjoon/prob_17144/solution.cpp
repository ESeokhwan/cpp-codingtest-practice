#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int _map[50][50];
vector<pair<int, pair<int, int> > > additions;
int cleaner;

pair<int, int> offsets[4] = {
  make_pair(0, 1),
  make_pair(-1, 0),
  make_pair(0, -1),
  make_pair(1, 0)
};


void spread() {
  for(int i = 0; i < r; i++) {
	for(int j = 0; j < c; j++) {
	  if(_map[i][j] == -1 || _map[i][j] == 0) continue;
	  int cnt = 0;
	  int si = _map[i][j] / 5;
	  for(auto offset : offsets) {
		int cur_r = i + offset.first;
		int cur_c = j + offset.second;
		if(cur_r < 0 || cur_r >= r || cur_c < 0 || cur_c >= c) continue;
		if(_map[cur_r][cur_c] == -1) continue;
		cnt++;
		additions.push_back(make_pair(si, make_pair(cur_r, cur_c)));
	  }
	  _map[i][j] -= (cnt * si);
	}
  }

  for(auto addition : additions) {
	_map[addition.second.first][addition.second.second] += addition.first;
  }
  additions.clear();
}

void clean(int st_r, bool reverse) {
  int tick = 1;
  if(reverse) tick = -1;

  bool is_visited = false;
  int dir = 0;
  int prev = 0;
  int cur_r = st_r;
  int cur_c = 0;
  while(true) {
	int nr = cur_r + offsets[dir].first;
	int nc = cur_c + offsets[dir].second;
	if(nr < 0 || nr >= r || nc < 0 || nc >= c) {
	  dir = ((dir + tick) + 4) % 4;
	  nr = cur_r + offsets[dir].first;
	  nc = cur_c + offsets[dir].second;
	}
	if(nr == st_r && nc == 0) break;

	int tmp = _map[nr][nc];
	_map[nr][nc] = prev;
	prev = tmp;
	cur_r = nr;
	cur_c = nc;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(_map, 0, sizeof(_map));

  cin >> r >> c >> t;
  bool is_first = false;
  for(int i = 0; i < r; i++) {
	for(int j = 0; j < c; j++) {
	  cin >> _map[i][j];
	  if(_map[i][j] == -1 && !is_first) {
		cleaner = i;
		is_first = true;
	  }
	}
  }

  for(int i = 0; i < t; i++) {
	spread();
	clean(cleaner, false);
	clean(cleaner + 1, true);
  }
  
  int res = 0;
  for(int i = 0; i < r; i++) {
	for(int j = 0; j < c; j++) {
	  res += _map[i][j];
	}
  }
  res += 2;
  cout << res << "\n";
  return 0;
}
