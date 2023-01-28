#include <bits/stdc++.h>
#define L_NUM 999999

using namespace std;

int N, M;

int init_v_map[50][50];

int v_map[50][50];
bool visited[50][50];

vector< pair< int, int > > p_virus;
pair< int, int > a_virus[10];

int res;

pair< int, int > offset_list[4] = {
  make_pair(1,0),
  make_pair(-1,0),
  make_pair(0,1),
  make_pair(0,-1)
};

void reset_visited() {
  for(int i = 0; i < 50; i++) memset(visited[i], false, 50*sizeof(bool));
}

void set_v_map() {
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  if(init_v_map[i][j] == 0) v_map[i][j] = L_NUM;
	  if(init_v_map[i][j] == 1) v_map[i][j] = -1;
	  if(init_v_map[i][j] == 2) v_map[i][j] = -2;
	}
  }
}

void simulate() {
  queue< pair<int, pair<int, int> > > q;
  reset_visited();
  set_v_map();

  for(int i = 0; i < M; i++) {
	reset_visited();
	q.push(make_pair(0, a_virus[i]));
	visited[a_virus[i].first][a_virus[i].second] = true;
	v_map[a_virus[i].first][a_virus[i].second] = 0;

	while(!q.empty()) {
	  int cp_r = q.front().second.first;
	  int cp_c = q.front().second.second;
	  int tick = q.front().first;
	  q.pop();

	  for(pair<int, int> offset : offset_list) {
		int np_r = cp_r + offset.first;
		int np_c = cp_c + offset.second;

		if(np_r < 0 || np_r >= N || np_c < 0 || np_c >= N) continue;
		if(visited[np_r][np_c]) continue;
		if(v_map[np_r][np_c] == -1) continue;
		if(v_map[np_r][np_c] != -2 && v_map[np_r][np_c] < tick+1) continue;

		q.push(make_pair(tick + 1, make_pair(np_r, np_c)));
		visited[np_r][np_c] = true;
		if(v_map[np_r][np_c] != -2) v_map[np_r][np_c] = tick+1; 
	  }
	}
  }
}

int get_max_tick() {
  int max_res = 0;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  if(v_map[i][j] <= max_res) continue;
	  if(v_map[i][j] == L_NUM) return L_NUM;

	  max_res = v_map[i][j];
	}
  }
  return max_res;
}

void recursion(int sp, int cnt) {
  if(cnt == M) {
	simulate();
	res = min(res, get_max_tick());

	return;
  }

  for(int i = sp; i < p_virus.size() - (M - cnt) + 1; i++) {
	a_virus[cnt] = p_virus[i];
	recursion(i+1, cnt+1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  res = L_NUM;

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  cin >> init_v_map[i][j];
	  if(init_v_map[i][j] == 2) p_virus.push_back(make_pair(i, j));
	}
  }

  recursion(0, 0);
  if(res == L_NUM) cout << "-1\n";
  else cout << res << "\n";
  cout << "\n";
  return 0;
}
