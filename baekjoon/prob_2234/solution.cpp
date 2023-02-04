#include <bits/stdc++.h>
using namespace std;

int N, M;

bool is_visited[50][50];
int wall[50][50];

int cnt;
int* rs_info[50][50];

pair<int, int> offset_list[4] = {
  make_pair(0, -1),
  make_pair(-1, 0),
  make_pair(0, 1),
  make_pair(1, 0)
};

void calc_room_size() {
  queue< pair< int, int > > q;

  for(int i = 0; i < M; i++) {
	for(int j = 0; j < N; j++) {
	  if(is_visited[i][j]) continue;
	  q.push(make_pair(i, j));
	  is_visited[i][j] = true;
	  int *rs = new int;
	  *rs = 1;
	  rs_info[i][j] = rs;
	  cnt++;
	  while(!q.empty()) {
		int cp_r = q.front().first;
		int cp_c = q.front().second;
		q.pop();

		int wall_info = wall[cp_r][cp_c];
		for(pair<int, int> offset : offset_list) {
		  if(wall_info % 2 == 0) { 
			int np_r = cp_r + offset.first;
			int np_c = cp_c + offset.second;
			if(!is_visited[np_r][np_c]) {
			  q.push(make_pair(np_r, np_c));
			  is_visited[np_r][np_c] = true;
			  rs_info[np_r][np_c] = rs;
			  (*rs) += 1;
			}
		  }
		  wall_info /= 2;
		}
	  }
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cnt = 0;
  for(int i = 0; i < M; i++) {
	memset(is_visited[i], false, sizeof(bool)*N);
  }

  cin >> N >> M;

  for(int i = 0; i < M; i++) {
	for(int j = 0; j < N; j++) {
	  cin >> wall[i][j];
	}
  }

  calc_room_size();

  int max_rs = 0;
  int max_rs_br = 0;
  for(int i = 0; i < M; i++) {
	for(int j = 0; j < N; j++) {
	  max_rs = max(max_rs, *rs_info[i][j]);
	  if(i != M-1) {
		if(rs_info[i][j] != rs_info[i+1][j]) 
		  max_rs_br = max(max_rs_br, (*rs_info[i][j])+(*rs_info[i+1][j]));
	  }
	  if(j != N-1) {
		if(rs_info[i][j] != rs_info[i][j+1]) 
		  max_rs_br = max(max_rs_br, (*rs_info[i][j])+(*rs_info[i][j+1]));
	  }
	}
  }

  cout << cnt << "\n" << max_rs << "\n" << max_rs_br << "\n";
  cout << "\n";
  return 0;
}
