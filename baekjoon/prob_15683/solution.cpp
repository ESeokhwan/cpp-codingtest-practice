#include <bits/stdc++.h>

using namespace std;

int N, M;

int res;
int o_map[10][10];
bool v_map[10][10];
vector< pair<int, int> > cam_pos_list;

vector < vector< pair< int, int> > > cam_dirs_list[5]; 

pair<int, int> cam_1_dirs[4][1] = {
  { make_pair(1, 0) }, 
  { make_pair(0, 1) },
  { make_pair(-1, 0) },
  { make_pair(0, -1) }
};

pair<int, int> cam_2_dirs[2][2] = {
  { make_pair(1, 0), make_pair(-1, 0) }, 
  { make_pair(0, 1), make_pair(0, -1) }
};

pair<int, int> cam_3_dirs[4][2] = {
  { make_pair(1, 0), make_pair(0, 1) }, 
  { make_pair(1, 0), make_pair(0, -1) },
  { make_pair(-1, 0), make_pair(0, 1) },
  { make_pair(-1, 0), make_pair(0, -1) }
};

pair<int, int> cam_4_dirs[4][3] = {
  { make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1) }, 
  { make_pair(1, 0), make_pair(-1, 0), make_pair(0, -1) }, 
  { make_pair(0, 1), make_pair(0, -1), make_pair(1, 0) }, 
  { make_pair(0, 1), make_pair(0, -1), make_pair(-1, 0) }, 
};

pair<int, int> cam_5_dirs[1][4] = {
  { make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1) }
};

void init_cam_dirs_init() {
  vector< pair<int, int> > cam_dirs;
  
  for(int i = 0; i < 4; i++) {
	cam_dirs.clear();
	for(int j = 0; j < 1; j++) cam_dirs.push_back(cam_1_dirs[i][j]);
	cam_dirs_list[0].push_back(cam_dirs);
  }
  
  for(int i = 0; i < 2; i++) {
	cam_dirs.clear();
	for(int j = 0; j < 2; j++) cam_dirs.push_back(cam_2_dirs[i][j]);
	cam_dirs_list[1].push_back(cam_dirs);
  }
  
  for(int i = 0; i < 4; i++) {
	cam_dirs.clear();
	for(int j = 0; j < 2; j++) cam_dirs.push_back(cam_3_dirs[i][j]);
	cam_dirs_list[2].push_back(cam_dirs);
  }
  
  for(int i = 0; i < 4; i++) {
	cam_dirs.clear();
	for(int j = 0; j < 3; j++) cam_dirs.push_back(cam_4_dirs[i][j]);
	cam_dirs_list[3].push_back(cam_dirs);
  }
  
  for(int i = 0; i < 1; i++) {
	cam_dirs.clear();
	for(int j = 0; j < 4; j++) cam_dirs.push_back(cam_5_dirs[i][j]);
	cam_dirs_list[4].push_back(cam_dirs);
  }
}

vector< pair<int, int> > set_v(int r, int c, vector< pair<int, int> > cam_dirs) {
  vector< pair<int, int> > last_added;
  for(pair<int, int> cam_dir : cam_dirs) {
	int nr = r;
	int nc = c;
	while(nr >= 0 && nr < N && nc >= 0 && nc < M) {
	  if(o_map[nr][nc] == 6) break;
	  if(v_map[nr][nc] == false) {
		last_added.push_back(make_pair(nr, nc));
		v_map[nr][nc] = true;
	  }
	  nr += cam_dir.first;
	  nc += cam_dir.second;
	}
  }
  return last_added;
}

void reset_v(vector< pair<int, int> > last_added) {
  for(pair<int, int> pos : last_added) {
	v_map[pos.first][pos.second] = false;
  }
}

int get_l_res() {
  int l_res = 0;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < M; j++) {
	  if(!v_map[i][j]) l_res++;
	}
  }
  return l_res;
}

void rec(int cnt) {
  if(cnt == cam_pos_list.size()) {
	res = min(res, get_l_res());
	return;
  }
  int cur_r = cam_pos_list[cnt].first;
  int cur_c = cam_pos_list[cnt].second;
  int cam_info = o_map[cur_r][cur_c];

  for(vector< pair<int, int> > cam_dirs : cam_dirs_list[cam_info-1]) {
	vector<pair<int, int> > last_added = set_v(cur_r, cur_c, cam_dirs);
	rec(cnt+1);
	reset_v(last_added);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  res = 999999;
  init_cam_dirs_init();
  cin >> N >> M;

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < M; j++) {
	  cin >> o_map[i][j];
	  if(o_map[i][j] == 6) {
		v_map[i][j] = true;
		continue;
	  }
	  if(o_map[i][j] > 0) cam_pos_list.push_back(make_pair(i, j));
	}
  }

  rec(0);

  cout << res << "\n";
  cout << "\n";
  return 0;
}

