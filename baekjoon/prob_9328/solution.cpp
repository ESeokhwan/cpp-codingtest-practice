#include <bits/stdc++.h>
using namespace std;

int n, h, w;
string key;
char _map[100][100];
bool visited[100][100];
bool open_d[26];
bool new_d_opened;
int res;

pair<int, int> offsets[4] = {
  make_pair(1, 0),
  make_pair(0, 1),
  make_pair(-1, 0),
  make_pair(0, -1)
};

bool can_pass(int r, int c) {
  int val = _map[r][c];

  if(val == '.' || val == '$') return true;
  if(val >= 'a' && val <= 'z') return true;
  if(val >= 'A' && val <= 'Z' && open_d[val - 'A']) return true; 
  return false;
}

void bfs(pair<int, int> sp) {
  queue<pair<int, int> >  q;
  q.push(make_pair(sp.first, sp.second));
  visited[sp.first][sp.second] = true;

  int cur_r, cur_c, cur_val;
  while(!q.empty()) {
	cur_r = q.front().first;
	cur_c = q.front().second;
	cur_val = _map[cur_r][cur_c];
	
	if(cur_val == '$') {
	  res += 1;
	  _map[cur_r][cur_c] = '.';
	} else if(cur_val >= 'a' && cur_val <= 'z') {
	  if(!open_d[cur_val - 'a']) {
		open_d[cur_val - 'a'] = true;
		new_d_opened = true;
	  }
	}
	q.pop();

	int n_r, n_c, n_val;
	for(pair<int, int> offset: offsets) {
	  n_r = cur_r + offset.first;
	  n_c = cur_c + offset.second;
	  if(n_r < 0 || n_r >= h || n_c < 0 || n_c >= w) continue;
	  if(visited[n_r][n_c]) continue;

	  n_val = _map[n_r][n_c];
	  if(!can_pass(n_r, n_c)) continue;
	  
	  q.push(make_pair(n_r, n_c));
	  visited[n_r][n_c] = true;
	}
  }
}

void solution() {
  res = 0;
  memset(open_d, false, sizeof(open_d));
  memset(visited, false, sizeof(visited));
  new_d_opened = true;

  cin >> h >> w;
  for(int i = 0; i < h; i++) {
	for(int j = 0; j < w; j++) cin >> _map[i][j];
  }

  cin >> key;
  if(key.compare("0") != 0) {
	for(int i = 0; i < key.size(); i++) {
	  open_d[key[i] - 'a'] = true;
	}
  }

  while(new_d_opened) {
	new_d_opened = false;
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < h; i++) {
	  if(i != 0 && i != h - 1) {
		if(can_pass(i, 0)) bfs(make_pair(i, 0));
		if(can_pass(i, w-1)) bfs(make_pair(i, w-1));
		continue;
	  }
	  for(int j = 0; j < w; j++) {
		if(can_pass(i, j)) bfs(make_pair(i, j));
	  }
	}
  }
  cout << res << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
	solution();
  }

  return 0;
}
