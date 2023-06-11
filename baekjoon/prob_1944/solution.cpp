#include <bits/stdc++.h>
using namespace std;

int n, m;
int _map[50][50];
vector<pair<int, pair<int, int> > > edges;

int rt[251];
int rk[251];

pair<int, int> st;
vector<pair<int, int> > keys;

pair<int, int> offsets[4] = {
  make_pair(1,0),
  make_pair(-1, 0),
  make_pair(0, 1),
  make_pair(0, -1)
};

void calc_dist(pair<int, int> pos) {
  queue<pair<pair<int, int>, int > > q;
  bool visited[50][50];
  memset(visited, false, sizeof(visited));

  q.push(make_pair(pos, 0));
  visited[pos.first][pos.second] = true;
  while(!q.empty()) {
	int cur_r = q.front().first.first;
	int cur_c = q.front().first.second;
	int dist = q.front().second;
	q.pop();
	if(_map[cur_r][cur_c] > 0 && !(cur_r == pos.first && cur_c == pos.second)) {
	  edges.push_back(make_pair(
			dist, make_pair(_map[pos.first][pos.second], _map[cur_r][cur_c])));
	}

	for(auto offset: offsets) {
	  int nr = cur_r + offset.first;
	  int nc = cur_c + offset.second;
	  if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
	  if(visited[nr][nc]) continue;
	  if(_map[nr][nc] == -1) continue;
	  q.push(make_pair(make_pair(nr, nc), dist + 1));
	  visited[nr][nc] = true;
	}
  }
}

void fill_edges() {
  calc_dist(st);
  for(int i = 0; i < m; i++) calc_dist(keys[i]);
}

void ds_init() {
  for(int i = 0; i < 251; i++) {
	rt[i] = i;
	rk[i] = 0;
  }
}

int ds_find(int x) {
  if(x == rt[x]) return x;
  return rt[x] = ds_find(rt[x]);
}

bool ds_union(int x, int y) {
  int rt_x = ds_find(x);
  int rt_y = ds_find(y);

  if(rt_x == rt_y) return false;

  if(rk[rt_x] > rk[rt_y]) {
	rt[rt_y] = rt_x;
  } else if(rk[rt_y] > rk[rt_x]) {
	rt[rt_x] = rt_y;
  } else {
	rt[rt_x] = rt_y;
	rk[rt_y]++;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	string input;
	cin >> input;
	for(int j = 0; j < n; j++) {
	  if(input[j] == '1') {
		_map[i][j] = -1;
	  } else if(input[j] == '0') {
		_map[i][j] = 0;
	  } else if(input[j] == 'S') {
		st = make_pair(i, j);
		_map[i][j] = 0;
	  } else if(input[j] == 'K') {
		keys.push_back(make_pair(i, j));
		_map[i][j] = keys.size();
	  }
	}
  }

  ds_init();
  fill_edges();
  sort(edges.begin(), edges.end());
  
  int cnt = 0;
  int res = 0;
  for(int i = 0; i < edges.size(); i++) {
	if(cnt == m) break;
	if(ds_union(edges[i].second.first, edges[i].second.second)) {
	  cnt += 1;
	  res += edges[i].first;
	}
  }
  if(cnt < m) res = -1;
  cout << res << "\n";
  return 0;
}
