#include <bits/stdc++.h>
using namespace std;

int w, h;
char _map[20][20];
pair<int, int> rp;
vector< pair<int, int> > dirts;
int graph[11][11];
set< int > not_visited;
int res;

pair<int, int> offsets[4] = {
  make_pair(1, 0),
  make_pair(-1, 0),
  make_pair(0, 1),
  make_pair(0, -1)
};

int get_distance(pair<int, int> sp, pair<int, int> ep) {
  bool is_visited[20][20];
  queue< pair< int, pair<int, int> > > q;

  memset(is_visited, false, sizeof(is_visited));
  
  q.push(make_pair(0, sp));
  is_visited[sp.first][sp.second] = true;
  while(!q.empty()) {
	for(auto offset : offsets) {
	  int cnt = q.front().first;
	  int nr = q.front().second.first + offset.first;
	  int nc = q.front().second.second + offset.second;

	  if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
	  if(is_visited[nr][nc]) continue;
	  if(_map[nr][nc] == 'x') continue;
	  if(nr == ep.first && nc == ep.second) {
		return cnt + 1;
	  }
	  q.push(make_pair(cnt + 1, make_pair(nr, nc)));
	  is_visited[nr][nc] = true;
	}
	q.pop();
  }
  return -1;
}

void fill_graph() {
  memset(graph, 0, sizeof(graph));
  for(int i = 0; i < dirts.size(); i++) {
	graph[0][i + 1] = get_distance(rp, dirts[i]);
	graph[i + 1][0] = graph[0][i + 1];
	for(int j = i + 1; j < dirts.size(); j++) {
	  graph[i + 1][j + 1] = get_distance(dirts[i], dirts[j]);
	  graph[j + 1][i + 1] = graph[i + 1][j + 1];
	}
  }
}

void traverse_graph(int acc, int cur) {
  if(not_visited.size() == 0) {
	if(res == -1) res = acc;
	else res = min(res, acc);
  }

  for(auto it = not_visited.begin(); it != not_visited.end(); it++) {
	int val = (*it);
	if(graph[cur][val] == -1) continue;
	not_visited.erase(val);
	traverse_graph(acc + graph[cur][val], val);
	not_visited.insert(val);
  }
}

void solution() {
  dirts.clear();
  not_visited.clear();
  for(int i = 0; i < h; i++) {
	string input;
	cin >> input;
	for(int j = 0; j < w; j++) {
	  _map[i][j] = input[j];
	  if(_map[i][j] == 'o') rp = make_pair(i, j);
	  if(_map[i][j] == '*') dirts.push_back(make_pair(i, j));
	}
  }

  fill_graph();
  
  res = -1;
  for(int i = 0; i < dirts.size(); i++) not_visited.insert(i + 1);
  traverse_graph(0, 0);
  cout << res << "\n";

  return;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(true) {
    cin >> w >> h;
	if(w == 0 && h == 0) break;
	solution();
  }
  return 0;
}
