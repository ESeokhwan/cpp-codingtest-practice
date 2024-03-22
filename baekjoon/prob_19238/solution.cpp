#include <bits/stdc++.h>
using namespace std;

int n, m, l;
int board[20][20];
pair<int, int> cp;
pair<pair<int, int>, pair<int, int> > p[400];
int dist[20][20];

pair<int, int> dirs[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void calc_dist() {
  queue<pair<pair<int, int>, int > > q;
  int visited[20][20];
  memset(dist, -1, sizeof(dist));

  q.push({ cp, 0 });
  dist[cp.first][cp.second] = 0;
  while(!q.empty()) {
	int cr = q.front().first.first;
	int cc = q.front().first.second;
	int cnt = q.front().second;
	q.pop();

	for (auto dir: dirs) {
	  int nr = cr + dir.first;
	  int nc = cc + dir.second;
	  if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
	  if(dist[nr][nc] != -1) continue;
	  if(board[nr][nc] == 1) continue;
	  dist[nr][nc] = cnt + 1;
	  q.push({ { nr, nc }, cnt + 1 });
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> l;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  cin >> board[i][j];
	}
  }

  int tmp1, tmp2;
  cin >> tmp1 >> tmp2;
  cp = {tmp1 - 1, tmp2 - 1};
  for (int i = 0; i < m; i++) {
	int st_r, st_c, en_r, en_c;
	cin >> st_r >> st_c >> en_r >> en_c;
	p[i] = { {st_r - 1, st_c - 1}, {en_r - 1, en_c - 1} };
  }
  sort(p, p + m);

  for (int i = 0; i < m; i++) {
	calc_dist();
	int min_dist = 10000000;
	int target_idx;
	for (int j = 0; j < m; j++) {
	  if (p[j].first.first == -1) continue;
	  if (dist[p[j].first.first][p[j].first.second] < min_dist) {
		target_idx = j;
		min_dist = dist[p[j].first.first][p[j].first.second];
	  }
	}
	if (l < min_dist || min_dist == -1) {
	  l = -1;
	  break;
	}
	
	l -= min_dist;
	cp = p[target_idx].first;
	calc_dist();
	if (l < dist[p[target_idx].second.first][p[target_idx].second.second]
		|| dist[p[target_idx].second.first][p[target_idx].second.second] == -1) {
	  l = -1;
	  break;
	}
	l += dist[p[target_idx].second.first][p[target_idx].second.second];
	cp = p[target_idx].second;
	p[target_idx].first.first = -1;
  }

  cout << l << "\n";
  return 0;
}
