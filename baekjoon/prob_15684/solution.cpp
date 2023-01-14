#include <bits/stdc++.h>

using namespace std;

int N, M, H, a, b;

bool hr_pos[32][12];
int sub_res[32][12];

int tick;

bool check_result(vector< int > goal_idx) {
  for(int i = 0; i < N; i++) 
	if(goal_idx[sub_res[H][i]] != i) 
	  return false;
  return true;
}

void recursion(int acc, pair< int, int > new_path, vector< int > goal_idx) {
  if(check_result(goal_idx)) {
	if(tick == -1 || tick > acc) tick = acc;
	return;
  }

  if(acc >= 3) return;

  for(int i = new_path.first; i < H; i++) {
	int start = 0;
	if(i == new_path.first) start = new_path.second + 2;

	for(int j = start; j < N-1; j++) {
	  if(hr_pos[i][j]) continue;
	  if(j > 0 && hr_pos[i][j-1]) continue;
	  if(j < N-2 && hr_pos[i][j+1]) continue;

	  int cur_val = sub_res[i][j];
	  int cur_nei_val = sub_res[i][j+1];
	  if(cur_val == sub_res[H][goal_idx[cur_val]]
		  && cur_nei_val == sub_res[H][goal_idx[cur_nei_val]])
		continue;

	  vector< int > new_goal_idx = goal_idx;
	  new_goal_idx[cur_nei_val] = goal_idx[cur_val];
	  new_goal_idx[cur_val] = goal_idx[cur_nei_val];
	  recursion(acc+1, make_pair(i, j), new_goal_idx);
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

  tick = -1;

  vector< int > init_goal;
  pair< int, int > init_new_path;

  for(int i = 0; i < 10; i++) init_goal.push_back(i);
  init_new_path = make_pair(0, -2);

  recursion(0, init_new_path, init_goal);

  cout << tick << "\n";
  cout << "\n";
  
  return 0;
}




