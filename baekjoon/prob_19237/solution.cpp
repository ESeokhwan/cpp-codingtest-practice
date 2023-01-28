#include <bits/stdc++.h>
using namespace std;

pair<int, int> offset_list[4] = {
  make_pair(-1, 0),
  make_pair(1, 0),
  make_pair(0, -1),
  make_pair(0, 1)
};

typedef struct shark {
  int num;
  int dir;

  int cp_r;
  int cp_c;

  int dir_priority[4][4];
  bool is_out;
} Shark;

typedef struct scent {
  int shark_num;
  int t;
} Scent;

Shark* shark_list[400];
Scent* scents[20][20];

int N, M, k;
int res;

int input;

void print() {
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  if(scents[i][j] == NULL) cout << "(-, -, -) ";
	  else cout << "(" << scents[i][j]->shark_num + 1 << ", " << scents[i][j]->t << ", " << shark_list[scents[i][j]->shark_num]->dir + 1 << ") ";
	}
	cout << "\n";
  }
  cout << "\n";
}

void update_scents() {
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  if(scents[i][j] == NULL) continue;
	  scents[i][j]->t -= 1;
	  if(scents[i][j]->t == 0) scents[i][j] = NULL;
	}
  }
}

void set_new_scents() {
  for(int i = 0; i < M; i++) {
	Shark *shark = shark_list[i];
	if(shark->is_out) continue;

	int cp_r = shark->cp_r;
	int cp_c = shark->cp_c;
	
	Scent *scent = scents[cp_r][cp_c];
	if(scent == NULL) {
	  scents[cp_r][cp_c] = new Scent();
	  scents[cp_r][cp_c]->shark_num = shark->num;
	  scents[cp_r][cp_c]->t = k;
	} else if(scent->shark_num >= shark->num) {
	  scent->shark_num = shark->num;
	  scent->t = k;
	} else {
	  shark->is_out = true;
	}
  }
}

pair<int, int> next_shark_pos(Shark* shark) {
  int dir = shark->dir;
  for(int i = 0; i < 4; i++) {
	pair<int, int> offset = offset_list[shark->dir_priority[dir][i]];
	int np_r = shark->cp_r + offset.first;
	int np_c = shark->cp_c + offset.second;
	if(np_r < 0 || np_r >= N || np_c < 0 || np_c >= N) continue;
	if(scents[np_r][np_c] == NULL) {
	  return make_pair(np_r, np_c);
	}
  }
  for(int i = 0; i < 4; i++) {
	pair<int, int> offset = offset_list[shark->dir_priority[dir][i]];
	int np_r = shark->cp_r + offset.first;
	int np_c = shark->cp_c + offset.second;
	if(np_r < 0 || np_r >= N || np_c < 0 || np_c >= N) continue;
	if(scents[np_r][np_c]->shark_num == shark->num) {
	  return make_pair(np_r, np_c);
	}
  }
  return make_pair(shark->cp_r, shark->cp_c);
}

void move_sharks() {
  for(int i = 0; i < M; i++) {
	if(shark_list[i]->is_out) continue;
	pair<int, int> np = next_shark_pos(shark_list[i]);
	for(int j = 0; j < 4; j++) {
	  pair<int, int> offset = offset_list[j];
	  if(offset.first == np.first - shark_list[i]->cp_r
		  && offset.second == np.second - shark_list[i]->cp_c) {
		shark_list[i]->dir = j;
		break;
	  }
	}
	shark_list[i]->cp_r = np.first;
	shark_list[i]->cp_c = np.second;
  }

}

void simulate() {
  int cnt = -1;
  while(cnt <= 1000) {
	bool is_all_out = true;
	for(int i = 1; i < M; i++) {
	  if(!shark_list[i]->is_out) {
		is_all_out = false;
		break;
	  }
	}
	if(is_all_out) {
	  res = cnt;
	  return;
	}

	set_new_scents();
	move_sharks();
	update_scents();
	cnt++;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> k;

  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  cin >> input;
	  if(input == 0) continue;
	  shark_list[input-1] = new Shark();
	  shark_list[input-1]->num = input-1;
	  shark_list[input-1]->cp_r = i;
	  shark_list[input-1]->cp_c = j;
	  shark_list[input-1]->is_out = false;
	}
  }

  for(int i = 0; i < M; i++) {
	cin >> input;
	shark_list[i]->dir = input-1;
  }

  for(int i = 0; i < M; i++) {
	for(int j = 0; j < 4; j++) {
	  for(int k = 0; k < 4; k++) {
		cin >> input;
		shark_list[i]->dir_priority[j][k] = input-1;
	  }
	}
  }

  res = -1;
  simulate();
  cout << res << "\n";
  cout << "\n";
  return 0;
}

