#include <bits/stdc++.h>
using namespace std;

int n, m;

int _map[1000][1000];
bool cb_visited[1000][1000];

int pr_map[1000][1000];
vector<int> c_blank;

int output[1000][1000];

pair<int, int> dirs[4] = {
  make_pair(1, 0),
  make_pair(0, 1),
  make_pair(-1, 0),
  make_pair(0, -1)
};

void check_blank() {
  memset(cb_visited, false, sizeof(cb_visited));
  memset(pr_map, -1, sizeof(pr_map));

  queue<pair<int, int> > q;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  if(_map[i][j] == 1) continue;
	  if(cb_visited[i][j]) continue;

	  int cnt = 0;
	  int idx = c_blank.size();
	  q.push(make_pair(i, j));
	  cb_visited[i][j] = true;
	  while(!q.empty()) {
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		cnt++;
		pr_map[cur_r][cur_c] = idx;
		
		for(auto dir : dirs) {
		  int ne_r = cur_r + dir.first;
		  int ne_c = cur_c + dir.second;

		  if(ne_r < 0 || ne_r >= n || ne_c < 0 || ne_c >= m) continue;
		  if(cb_visited[ne_r][ne_c]) continue;
		  if(_map[ne_r][ne_c] == 1) continue;
		  q.push(make_pair(ne_r, ne_c));
		  cb_visited[ne_r][ne_c] = true;
		}
	  }
	  c_blank.push_back(cnt);
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	string input;
	cin >> input;
	for(int j = 0; j < m; j++) {
	  _map[i][j] = (int) (input[j] - '0');
	}
  }
  
  check_blank();

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) {
	  output[i][j] = 0;
	  if(_map[i][j] == 0) continue;

	  output[i][j]++;
	  set<int> b_set;
	  for(auto dir: dirs) {
		int ne_r = i + dir.first;
		int ne_c = j + dir.second;
		if(ne_r < 0 || ne_r >= n || ne_c < 0 || ne_c >= m) continue;
		if(_map[ne_r][ne_c] == 1) continue;
		if(b_set.insert(pr_map[ne_r][ne_c]).second) {
		  output[i][j] += c_blank[pr_map[ne_r][ne_c]];
		}
	  }
	}
  }

  for(int i = 0; i < n; i++) {
	for(int j = 0; j < m; j++) cout << output[i][j] % 10;
	cout << "\n";
  }

  cout << "\n";
  return 0;
}
