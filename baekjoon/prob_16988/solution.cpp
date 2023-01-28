#include <bits/stdc++.h>
using namespace std;

int N, M;

int table[20][20];
bool visited[20][20];

vector< pair< int, set< pair< int, int > > > > bound_list;
vector< pair< int, set< pair< int, int > > > > reduced_bound_list[4];

pair< int, int > offset_list[4] = {
  make_pair( 1, 0 ),
  make_pair(-1, 0 ),
  make_pair( 0, 1 ),
  make_pair( 0,-1 )
};

int max_res;

void bfs() {
  queue< pair< int, int > > q;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < M; j++) {
	  if(visited[i][j]) continue;

	  visited[i][j] = true;
	  if(table[i][j] == 2) {
		q.push(make_pair(i, j));
		set< pair<int, int> > new_bound;
		bound_list.push_back(make_pair(0, new_bound));
	  }
	  while(!q.empty()) {
		int cp_r = q.front().first;
		int cp_c = q.front().second;
		q.pop();

		if(table[cp_r][cp_c] == 2) {
		  bound_list.back().first++;
		  for(pair< int, int > offset : offset_list) {	
			int nr = cp_r + offset.first;
			int nc = cp_c + offset.second;
			if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if(table[nr][nc] == 0) bound_list.back().second.insert(make_pair(nr, nc));
			if(!visited[nr][nc]) {
			  visited[nr][nc] = true;
			  q.push(make_pair(nr, nc));
			}
		  }
		}
	  }
	}
  }
}


void get_max_dead_stone(int cnt) {
  int local_max = 0;
  for(int i = 0; i < reduced_bound_list[cnt].size(); i++) {
	if(reduced_bound_list[cnt][i].second.size() == 0) {
	  local_max += reduced_bound_list[cnt][i].first;
	}
  }
  max_res = max(max_res, local_max);
  
  for(int i = 0; i < reduced_bound_list[cnt].size(); i++) {
	if(reduced_bound_list[cnt][i].second.size() == 0) continue;
	
	int next_cnt = cnt + reduced_bound_list[cnt][i].second.size();
	if(next_cnt > 2) continue;

	reduced_bound_list[next_cnt] = reduced_bound_list[cnt];
	set<pair<int, int > >::iterator it;
	for(
		it = reduced_bound_list[cnt][i].second.begin(); 
		it != reduced_bound_list[cnt][i].second.end(); it++) {
	  for(int j = 0; j < reduced_bound_list[next_cnt].size(); j++) {
		reduced_bound_list[next_cnt][j].second.erase(*(it));
	  }
	}
	get_max_dead_stone(next_cnt);
  }
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < M; j++) {
	  cin >> table[i][j];
	  visited[i][j] = false;
	}
  }

  bfs();
  
  for(int i = 0; i < bound_list.size(); i++) {
	if(bound_list[i].second.size() <= 2) reduced_bound_list[0].push_back(bound_list[i]);
  }

  get_max_dead_stone(0);

  cout << max_res << "\n";
  cout << "\n";
  return 0;
}
