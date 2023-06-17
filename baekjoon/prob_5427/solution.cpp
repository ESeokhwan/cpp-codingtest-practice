#include <bits/stdc++.h>
using namespace std;

int n;

int w, h;
pair<int, int> st;

int _map[1000][1000];
int f_map[1000][1000];
bool visited[1000][1000];
vector<pair<int, int> > fires;

pair<int, int> dirs[4] = {
  make_pair(1, 0),
  make_pair(-1, 0),
  make_pair(0, 1),
  make_pair(0, -1)
};

void f_bfs() {
  queue<pair<int, pair<int, int> > > q;
  bool visited[1000][1000];
  memset(visited, false, sizeof(visited));

  for(int i = 0; i < fires.size(); i++) {
	q.push(make_pair(1, fires[i]));
	visited[fires[i].first][fires[i].second] = true;
  }

  while(!q.empty()) {
	int cur_acc = q.front().first;
	int cur_r = q.front().second.first;
	int cur_c = q.front().second.second;
	q.pop();
	_map[cur_r][cur_c] = cur_acc;

	for(auto dir: dirs) {
	  int nr = cur_r + dir.first;
	  int nc = cur_c + dir.second;
	  if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
	  if(_map[nr][nc] == -1) continue;
	  if(visited[nr][nc]) continue;
	  q.push(make_pair(cur_acc + 1, make_pair(nr, nc)));
	  visited[nr][nc] = true;
	}
  }
}

int bfs() {
  queue<pair<int, pair<int, int> > > q;
  bool visited[1000][1000];
  memset(visited, false, sizeof(visited));

  q.push(make_pair(0, st));
  while(!q.empty()) {
	int cur_acc = q.front().first;
	int cur_r = q.front().second.first;
	int cur_c = q.front().second.second;
	q.pop();
	
	for(auto dir: dirs) {
	  int nr = cur_r + dir.first;
	  int nc = cur_c + dir.second;
	  if(nr < 0 || nr >= h || nc < 0 || nc >= w) return cur_acc + 1;
	  if(_map[nr][nc] == -1) continue;
	  if(_map[nr][nc] != 0 && cur_acc >= _map[nr][nc] - 2) continue;
	  if(visited[nr][nc]) continue;

	  q.push(make_pair(cur_acc + 1, make_pair(nr, nc)));
	  visited[nr][nc] = true;
	}
  }
  return -1;
}

void solution() {
  fires.clear();
  cin >> w >> h;
  for(int i = 0; i < h; i++) {
	string input_str;
	cin >> input_str;
	for(int j = 0; j < w; j++) {
	  if(input_str[j] == '#') {
		_map[i][j] = -1;
	  } else {
		if(input_str[j] == '*') fires.push_back(make_pair(i, j));
		if(input_str[j] == '@') st = make_pair(i, j);
		_map[i][j] = 0;
	  }
	}
  }

  f_bfs();
  int res = bfs();
  if(res == -1) cout << "IMPOSSIBLE\n";
  else cout << res << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  for(int i = 0; i < n; i++) solution();

  return 0;
}
