#include <bits/stdc++.h>
using namespace std;

int n, res;
char _map[50][50];
pair<int, int> st, en;

bool visited[50][50][4];
pair<int, int> dirs[4] = {
  make_pair(-1, 0),
  make_pair(0, 1),
  make_pair(1, 0),
  make_pair(0, -1)
};

void bfs() {
  queue<tuple<int, int, int, int> > q;
  for(int i = 0; i < 4; i++) {
	q.push(make_tuple(st.first, st.second, i, 0));
	visited[st.first][st.second][i] = true;
  }
  
  while(!q.empty()) {
	int cur_r = get<0>(q.front());
	int cur_c = get<1>(q.front());
	int cur_d = get<2>(q.front());
	int acc = get<3>(q.front());
	q.pop();

	cur_r += dirs[cur_d].first;
    cur_c += dirs[cur_d].second;
    while(cur_r >= 0 && cur_r < n && cur_c >= 0 && cur_c < n) {
	  if(cur_r == en.first && cur_c == en.second) {
		res = acc;
		return;
	  }
	  
	  if(_map[cur_r][cur_c] == '*') break;
	  if(_map[cur_r][cur_c] == '!') {
		if(visited[cur_r][cur_c][(cur_d + 1) % 4] != true) {
		  q.push(make_tuple(cur_r, cur_c, (cur_d + 1) % 4, acc + 1));
		  visited[cur_r][cur_c][(cur_d + 1) % 4] = true;
		}
		if(visited[cur_r][cur_c][(cur_d + 3) % 4] != true) {
		  q.push(make_tuple(cur_r, cur_c, (cur_d + 3) % 4, acc + 1));
		  visited[cur_r][cur_c][(cur_d + 3) % 4] = true;
		}
	  }
	  cur_r += dirs[cur_d].first;
	  cur_c += dirs[cur_d].second;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(visited, false, sizeof(visited));

  string input;
  cin >> n;
  for(int i = 0; i < n; i++) {
	cin >> input;
	for(int j = 0; j < n; j++) {
	  _map[i][j] = input[j];
	  if(_map[i][j] == '#') {
		en = st;
		st = make_pair(i, j);
	  }
	}
  }

  bfs();
  cout << res << "\n";
  return 0;
}
