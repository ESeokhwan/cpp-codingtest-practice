#include <bits/stdc++.h>
using namespace std;

int h, w;
int _map[1000][1000];
bool visited[1000][1000];

queue<pair<int, pair<int, int > > > q;
pair<int, int> dirs[8] = {
  { 1, -1 }, { 1, 0 }, { 1, 1 },
  { 0, -1 }, { 0, 1 }, { -1, -1 },
  { -1, 0 }, { -1, 1 } 
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(visited, false, sizeof(visited));
  cin >> h >> w;
  for(int i = 0; i < h; i++) {
	for(int j = 0; j < w; j++) {
	  char input;
	  cin >> input;
	  if(input == '.') {
		_map[i][j] = 0;
		q.push({ 1, { i, j } });
	  } else {
		_map[i][j] = input - '0';
	  }
	}
  }

  int prev_cnt = 0;
  while(!q.empty()) {
	int cnt = q.front().first;
	int cur_r = q.front().second.first;
	int cur_c = q.front().second.second;
	visited[cur_r][cur_c] = true;
	q.pop();

	if(cnt != prev_cnt) {
	  prev_cnt = cnt;
	}

	for(auto dir: dirs) {
	  int next_r = cur_r + dir.first;
	  int next_c = cur_c + dir.second;
	  if(next_r < 0 || next_r >= h || next_c < 0 || next_c >= w) continue;
	  if(_map[next_r][next_c] == 0) continue;
	  _map[next_r][next_c] -= 1;
	  if(_map[next_r][next_c] == 0) {
		q.push({ cnt + 1, { next_r, next_c } });
	  }
	}
  }

  cout << prev_cnt - 1 << "\n";
  return 0;
}
