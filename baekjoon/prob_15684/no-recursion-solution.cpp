#include <bits/stdc++.h>

using namespace std;

int N, M, H, a, b;

bool hr_pos[32][12];
int sub_res[32][12];

vector< vector< int > > goal_idx[2];
vector< pair< int, int > > addition[2];

pair< int, int > new_path;
vector< int > tmp_goal;

int cnt, tick;
bool is_end;

bool check_result() {
  for(int i = 0; i < N; i++) 
	if(tmp_goal[sub_res[H][i]] != i) 
	  return false;
  return true;
}

void tracking() {
  if(check_result()) {
	tick = cnt + 1;
	is_end = true;
	return;
  }

  for(int i = new_path.first; i < H; i++) {
	int start = 0;
	if(i == new_path.first) {
	  start = new_path.second + 2;
	}

	for(int j = start; j < N-1; j++) { 
	  if(hr_pos[i][j]) continue;
	  if(j > 0 && hr_pos[i][j-1]) continue;
	  if(j < N-1 && hr_pos[i][j+1]) continue;
	  
	  int cur_val = sub_res[i][j];
	  int cur_nei_val = sub_res[i][j+1];
	  if(cur_val == sub_res[H][tmp_goal[cur_val]]
		  || cur_nei_val == sub_res[H][tmp_goal[cur_nei_val]])
		continue;

	  vector< int > cpy;
	  cpy.insert(cpy.begin(), tmp_goal.begin(), tmp_goal.end());
	  
	  int tmp = cpy[sub_res[i][j]];
	  cpy[sub_res[i][j]] = cpy[sub_res[i][j+1]];
	  cpy[sub_res[i][j+1]] = tmp;
  
	  addition[(cnt+1)%2].push_back(make_pair(i, j));
	  goal_idx[(cnt+1)%2].push_back(cpy);
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 32; i++) 
	memset(hr_pos[i], false, sizeof(bool) * 12);

  for(int i = 0; i < 12; i++) {
	sub_res[0][i] = i;
  }

  cin >> N >> M >> H;
  for(int i = 0; i < M; i++) {
	cin >> a >> b;
	hr_pos[a - 1][b - 1] = true;
  }

  for(int i = 0; i < H; i++) {
	for(int j = 0; j < N; j++) {
	  if(hr_pos[i][j]) {
		sub_res[i+1][j] = sub_res[i][j+1];
		sub_res[i+1][j+1] = sub_res[i][j];
		j++;
	  } else {
		sub_res[i+1][j] = sub_res[i][j];
	  }
	}
  }

  is_end = false;
  tick = -1;
  cnt = -1;
  for(int i = 0; i < 10; i++) tmp_goal.push_back(i);
  new_path = make_pair(0, -2);
  tracking();

  if(is_end) {
	cout << tick << "\n";
	cout << "\n";
	return 0;
  }
  
  for(cnt = 0; cnt < 3; cnt++) {
	for(int i = 0; i < addition[cnt%2].size(); i++) {
	  pair< int, int > new_path = addition[cnt%2][i];
	  tmp_goal = goal_idx[cnt%2][i];

	  tracking();
	  if(is_end) break;
	}
	if(is_end) break;
  }
  
  cout << tick << "\n";
  cout << "\n";
  
  return 0;
}

