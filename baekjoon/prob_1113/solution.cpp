#include <bits/stdc++.h>
using namespace std;

int w, h;
int _map[50][50];
int depth[50][50];

pair<int, int> dirs[4] = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

void bfs() {
  vector<pair<int, int> > container;
  queue<pair<int, int> > q;
  bool visited[50][50];
  memset(visited, false, sizeof(visited));

  int st_height = 10;
  int st_r, st_c;
  for(int i = 0; i < h; i++) {
	for(int j = 0; j < w; j++) {
	  if(_map[i][j] < st_height) {
		st_r = i;
		st_c = j;
		st_height = _map[i][j];
	  }
	}
  }
  
  bool spilled = false;
  int height = 10;
  int basis = _map[st_r][st_c];
  q.push({st_r, st_c});
  while(!q.empty()) {
	int cur_r = q.front().first;
	int cur_c = q.front().second;
	q.pop();

	if(cur_r < 0 || cur_r >= h || cur_c < 0 || cur_c >= w) {
	  spilled = true;
	  continue;
	}
	if(visited[cur_r][cur_c]) continue;
	if(_map[cur_r][cur_c] > basis) {
	  height = min(height, _map[cur_r][cur_c]);
	  continue;
	}
	visited[cur_r][cur_c] = true;
	container.push_back({cur_r, cur_c});

	for(auto dir : dirs) q.push({cur_r + dir.first, cur_c + dir.second});
  }
  
  for(auto pos: container) {
	if(!spilled) {
	  depth[pos.first][pos.second] += (height - _map[pos.first][pos.second]);
	}
	_map[pos.first][pos.second] = height;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(depth, 0, sizeof(depth));
  cin >> h >> w;
  for(int i = 0; i < h; i++) {
	for(int j = 0; j < w; j++) {
	  char input;
	  cin >> input;
	  _map[i][j] = (int) (input - '0');
	}
  }

  int res = 0;
  while(_map[0][0] != 10) bfs();
  for(int i = 0; i < h; i++) {
	for(int j = 0; j < w; j++) res += depth[i][j];
  }

  cout << res << "\n";
  return 0;
}
