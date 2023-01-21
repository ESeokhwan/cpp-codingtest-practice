#include <bits/stdc++.h>
using namespace std;

int R, C, M;

bool is_turn;
int cur_table;
pair< int, pair<int, int> > sharks[100][100][2];

pair< int, int > offset[4] = {
  make_pair(-1, 0),
  make_pair(1, 0),
  make_pair(0, 1),
  make_pair(0, -1)
};

int next_shark_pos(int prev, int v, int size) {
	is_turn = false;
	int tmp = (prev + v) % (2 * (size - 1));
	if(tmp < 0) {
	  is_turn = true;
	  tmp = -1 * tmp;
	}
    if(tmp < size) {
	return tmp;
  }
  is_turn = !is_turn;
  return 2*(size-1)-tmp;
}

void move_shark() {
  int size;
  pair<int, int> v;

  for(int i = 0; i < R; i++) {
	for(int j = 0; j < C; j++) {
	  sharks[i][j][(cur_table + 1) % 2].first = 0;
	}
  }

  for(int i = 0; i < R; i++) {
	for(int j = 0; j < C; j++) {
	  size = sharks[i][j][cur_table%2].first;
	  v = sharks[i][j][cur_table%2].second;

	  int new_r = next_shark_pos(i, v.first, R);
	  if(is_turn) {
		v.first = -v.first;
	  }
	  int new_c = next_shark_pos(j, v.second, C);
	  if(is_turn) {
		v.second = -v.second;
	  }
	  if(sharks[new_r][new_c][(cur_table+1)%2].first < size) {
		sharks[new_r][new_c][(cur_table+1)%2] = 
		  make_pair(size, make_pair(v.first, v.second));
	  }
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C >> M;

  cur_table = 0;
  int r, c, s, d, z;
  for(int i=0; i<M; i++) {
	cin >> r >> c >> s >> d >> z;
	sharks[r-1][c-1][0] = make_pair(z, make_pair(s*offset[d-1].first, s*offset[d-1].second));
  }
  
  int catched = 0;
  for(int i = 0; i < C; i++) {
	cur_table = i;
	for(int j = 0; j < R; j++) {
	  if(sharks[j][i][cur_table%2].first != 0) {
		catched += sharks[j][i][cur_table%2].first;
		sharks[j][i][cur_table%2].first = 0;
		break;
	  }
	}
	move_shark();
  }

  cout << catched << "\n";
  cout << "\n";
  return 0;
}
