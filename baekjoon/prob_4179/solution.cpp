#include <bits/stdc++.h>

using namespace std;

int R, C;
char maze[1005][1005];

bool j_reach_map[1005][1005];

vector< pair< int, int > > j_pos_list[2];
vector< pair< int, int > > f_round_list[2];

bool is_end;
int tick;


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  is_end = false;
  for(int i = 0; i < 1005; i++) {
	memset(j_reach_map[i], false, 1005*sizeof(bool));
  }

  cin >> R >> C;
  for(int i = 0; i < R; i++) {
	for(int j = 0; j < C; j++) {
	  cin >> maze[i][j];
	  if(maze[i][j] == 'J') {
		j_pos_list[0].push_back(make_pair(i, j));
		j_reach_map[i][j] = true;
		maze[i][j] = '.';
	  }
	  if(maze[i][j] == 'F') {
		f_round_list[0].push_back(make_pair(i, j));
	  }
	}
  }

  pair< int, int > offset_list[4] = {
	make_pair(1, 0),
	make_pair(0, 1),
	make_pair(-1, 0), 
	make_pair(0, -1)
  };

  for(int i = 0; !j_pos_list[i%2].empty(); i++) {
	f_round_list[(i+1)%2].clear();
	for(pair< int, int > f_pos : f_round_list[i%2]) {
	  for(pair< int, int > offset : offset_list) {
		int new_row = f_pos.first + offset.first;
		int new_col = f_pos.second + offset.second;

		if(new_row >= R || new_row < 0 || new_col >= C || new_col < 0) continue;

		if(maze[new_row][new_col] == '.') {
		  maze[new_row][new_col] = 'F';
		  f_round_list[(i+1)%2].push_back(make_pair(new_row, new_col));
		}
	  }
	}

	j_pos_list[(i+1)%2].clear();
	for(pair< int, int > j_pos : j_pos_list[i%2]) {
	  for(pair< int, int > offset : offset_list) {
		int new_row = j_pos.first + offset.first;
		int new_col = j_pos.second + offset.second;

		if(new_row >= R || new_row < 0 || new_col >= C || new_col < 0) {
		  is_end = true;
		  break;
		}

		if(j_reach_map[new_row][new_col]) continue;

		if(maze[new_row][new_col] == '.') {
		  j_pos_list[(i+1)%2].push_back(make_pair(new_row, new_col));
		  j_reach_map[new_row][new_col] = true;
		}
	  }

	  if(is_end) {
		break;
	  }
	}
	if(is_end) {
	  tick = i;
	  break;
	}
  }

  if(is_end) {
	cout << tick + 1 << "\n";
  } else {
	cout << "IMPOSSIBLE\n";
  }

  cout << "\n";
  return 0;
}

