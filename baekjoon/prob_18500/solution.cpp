#include "bits/stdc++.h"
using namespace std;

int R, C, N;
char _map[100][100];
int seq[100];

bool visited[100][100];
int dirs[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; 

pair<bool, vector<pair<int, int> > > bfs(int st_r, int st_c) {
  vector<pair<int, int> > cluster;
  bool isOnTheGround = false;
  if (visited[st_r][st_c] == true || _map[st_r][st_c] == '.') {
	return { isOnTheGround, cluster }; 
  }

  queue<pair<int, int> > q;

  q.push({st_r, st_c});
  visited[st_r][st_c] = true;
  while (!q.empty()) {
	int cur_r = q.front().first;
	int cur_c = q.front().second;
	q.pop();
	cluster.push_back({ cur_r, cur_c });
	if (cur_r == R - 1) {
	  isOnTheGround = true;
	}

	for (auto dir: dirs) {
	  int ne_r = cur_r + dir[0];
	  int ne_c = cur_c + dir[1];
	  if (ne_r < 0 || ne_r >= R || ne_c < 0 || ne_c >= C) continue;
	  if (visited[ne_r][ne_c] == true || _map[ne_r][ne_c] == '.') continue;
	  q.push({ne_r, ne_c});
	  visited[ne_r][ne_c] = true;
	}
  }
  return { isOnTheGround, cluster };
}

void move_float_cluster() {
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  pair<bool, vector<pair<int, int> > > cluster_info = bfs(i, j);
	  if (cluster_info.first == true || cluster_info.second.size() == 0) continue;
//	  cout << "move cluster(" << cluster_info.second.size() << ")\n";
	  vector<pair<int, int> > cluster = cluster_info.second;
	  
	  bool same_cluster[100][100];
	  memset(same_cluster, false, sizeof(same_cluster));
	  for (auto p: cluster) same_cluster[p.first][p.second] = true;

	  int dist = R;
	  for (auto p: cluster) {
		int tmp_dist = 0;
	    bool is_floor = true;
		for (int k = p.first + 1; k < R; k++) {
		  if (same_cluster[k][p.second] == true) {
			is_floor = false;
			break;
		  }
		  if (_map[k][p.second] == 'x') break;
		  tmp_dist += 1;
		}
		if (is_floor == true) dist = min(dist, tmp_dist);
	  }

	  sort(cluster.begin(), cluster.end());
	  for (int i = cluster.size() - 1; i >= 0; i--) {
		int r = cluster[i].first;
		int c = cluster[i].second;
//		cout << "before : " << r << ", " << c << "\n";
//		cout << "after : " << r + dist << ", " << c << "\n";
		_map[r][c] = '.';
		_map[r + dist][c] = 'x';
	  }
	  return;
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  cin >> _map[i][j];
	}
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
	int input;
	cin >> input;
	seq[i] = R - input;
  }

  for (int i = 0; i < N; i++) {
	int mult = 1;
	if (i % 2 == 1) {
	  mult = -1;
	}
//	cout << i << "th\n";
	for (int j = min(0, mult * C + 1); j <= max(0, mult * C - 1); j++) {
	  int tmp_j = j * mult;
	  if (_map[seq[i]][tmp_j] == '.') continue;
	  _map[seq[i]][tmp_j] = '.';
	  move_float_cluster();
	  break;
	}
  }

  for (int i = 0; i < R; i++) {
	for (int j = 0; j < C; j++) {
	  cout << _map[i][j];
	}
	cout << "\n";
  }
  return 0;
}
