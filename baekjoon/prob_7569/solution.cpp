#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int tomatos[100][100][100];

tuple<int, int, int> dirs[6] = {
  make_tuple(1, 0, 0),
  make_tuple(-1, 0, 0),
  make_tuple(0, 1, 0),
  make_tuple(0, -1, 0),
  make_tuple(0, 0, 1),
  make_tuple(0, 0, -1)
};

int bfs() {
  queue<pair<int, tuple<int, int, int> > > q;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  for(int k = 0; k < h; k++) {
		if(tomatos[i][j][k] == 1) q.push(make_pair(0, make_tuple(i, j, k)));
	  }
	}
  }

  int res;
  while(!q.empty()) {
	int cur_r = get<0>(q.front().second);
	int cur_c = get<1>(q.front().second);
	int cur_h = get<2>(q.front().second);
	int cnt = q.front().first;
	q.pop();
	res = cnt;

	for(auto dir: dirs) {
	  int nr = cur_r + get<0>(dir);
	  int nc = cur_c + get<1>(dir);
	  int nh = cur_h + get<2>(dir);

	  if(nr < 0 || nr >= n || nc < 0 || nc >= m || nh < 0 || nh >= h) continue;
	  if(tomatos[nr][nc][nh] != 0) continue;
	  tomatos[nr][nc][nh] = 1;
	  q.push(make_pair(cnt + 1, make_tuple(nr, nc, nh)));
	}
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> m >> n >> h;
  for(int i = 0; i < h; i++) {
	for(int j = 0; j < n; j++) {
	  for(int k = 0; k < m; k++) cin >> tomatos[j][k][i];
	}
  }

  int res = bfs();
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  for(int k = 0; k < h; k++) {
		if(tomatos[i][j][k] == 0) {
		  cout << "-1\n";
		  return 0;
		}
	  }
	}
  }
  cout << res << "\n";
  return 0;
}
