#include <bits/stdc++.h>
using namespace std;

int INF = 100000;
int n, res;
int _map[100][100];

vector<tuple<int, int, int> > sps;

pair<int, int> offsets[4] = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };

void init_map() {
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) _map[i][j] = INF;
  }
}

void find_sps() {
  queue<pair<int, int> > q;
  bool visited[100][100];
  memset(visited, false, sizeof(visited));

  int cnt = 0;
  for(int i = 0; i < 100; i++) {
	for(int j = 0; j < 100; j++) {
	  if(_map[i][j] == 0) continue;
	  if(visited[i][j]) continue;
	  cnt += 1;
	  q.push( {i, j} );
	  visited[i][j] = true;
	  _map[i][j] = cnt;
	  while(!q.empty()) {
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();

		for(auto offset : offsets) {
		  int next_r = cur_r + offset.first;
		  int next_c = cur_c + offset.second;
		  if(next_r >= n || next_r < 0 || next_c >= n || next_c < 0) continue;
		  if(visited[next_r][next_c]) continue;
		  
		  if(_map[next_r][next_c] == 0) sps.push_back({ cnt, next_r, next_c });
		  else {
			q.push({next_r, next_c}); 
			_map[next_r][next_c] = cnt;
		  }
		  visited[next_r][next_c] = true;
		}
	  }
	}
  }
}

void find_res(int land_num, int sp_r, int sp_c) {
  queue<pair<int, pair<int, int> > > q;
  bool visited[100][100];
  memset(visited, false, sizeof(visited));

  q.push( { 0, {sp_r, sp_c} } );
  visited[sp_r][sp_c] = true;
  while(!q.empty()) {
	int cnt = q.front().first;
	int cur_r = q.front().second.first;
	int cur_c = q.front().second.second;
	q.pop();

	for(auto offset : offsets) {
	  int next_r = cur_r + offset.first;
	  int next_c = cur_c + offset.second;
	  if(next_r >= n || next_r < 0 || next_c >= n || next_c < 0) continue;
	  if(visited[next_r][next_c]) continue;
	  
	  if(_map[next_r][next_c] == 0) {
		q.push({cnt + 1, {next_r, next_c}});
		visited[next_r][next_c] = true;
	  }
	  else if(_map[next_r][next_c] != land_num) {
		res = min(res, cnt + 1);
	  }
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  init_map();
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) cin >> _map[i][j];
  }

  res = 1000000;
  find_sps();
  for(auto sp : sps) {
	int land_num = get<0>(sp);
	int sp_r = get<1>(sp);
	int sp_c = get<2>(sp);

	find_res(land_num, sp_r, sp_c);
  }
  
  cout << res << "\n";
  return 0;
}
