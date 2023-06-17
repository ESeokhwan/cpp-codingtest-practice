#include <bits/stdc++.h>
using namespace std;

int w, h;
int res;

char _map[100][100];
int dp[100][100];
pair<int, int> st;
pair<int, int> en;

pair<int, int> dirs[4] = {
  make_pair(-1, 0),
  make_pair(0, 1), 
  make_pair(1, 0),
  make_pair(0, -1)
};

void init_dp() {
  for(int i = 0; i < 100; i++) {
	for(int j = 0; j < 100; j++) {
	  dp[i][j] = -1;
	}
  }
}

void bfs() {
  queue<pair<pair<int, int>, pair<int, int> > > q;
  init_dp();

  q.push(make_pair(make_pair(0, -1), st));
  dp[st.first][st.second] = 0;
  while(!q.empty()) {
	int cur_acc = q.front().first.first;
	int prev_dir = q.front().first.second;
	int cur_r = q.front().second.first;
	int cur_c = q.front().second.second;
	q.pop();

	for(int i = 0; i < 4; i++) {
	  auto dir = dirs[i];
	  if(i == prev_dir) continue;
	  for(int j = 0; true; j++) {
		int nr = cur_r + dir.first * j;
		int nc = cur_c + dir.second * j;
		if(nr < 0 || nr >= h || nc < 0 || nc >= w) break;
		if(_map[nr][nc] == '*') break;
		if(dp[nr][nc] != -1) continue;
		q.push(make_pair(make_pair(cur_acc + 1, i), make_pair(nr, nc)));
		dp[nr][nc] = cur_acc + 1;
	  }
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  bool isFirst = true;

  cin >> w >> h;
  for(int i = 0; i < h; i++) {
	string input_str;
	cin >> input_str;
	for(int j = 0; j < w; j++) {
	  _map[i][j] = input_str[j];
	  if(_map[i][j] == 'C') {
		if(isFirst) {
		  st = make_pair(i, j);
		  isFirst = false;
		} else {
		  en = make_pair(i, j);
		}
	  }
	}
  }

  res = 100000;
  bfs();
  cout << dp[en.first][en.second] - 1 << "\n";
  return 0;
}
