#include <bits/stdc++.h>
using namespace std;

int N;

int res;

bool chess_map[15][15];
int offset[3][2] = {{1, -1}, {1, 0}, {1,1}};
stack<pair< int, pair<int, int > > > addition;

void add_queen(int r, int c) {
  int tmp_r, tmp_c;
  for(int i = 0; i <= N; i++) {
	for(int j = 0; j < 3; j++) {
	  tmp_r = r + offset[j][0] * i;
	  tmp_c = c + offset[j][1] * i;
	  if(tmp_r < 0 || tmp_r >= N || tmp_c < 0 || tmp_c >=N) continue;
	  if(!chess_map[tmp_r][tmp_c]) {
		chess_map[tmp_r][tmp_c] = true;
		addition.push(make_pair(r, make_pair(tmp_r, tmp_c)));
	  }
	}
  }
}

void reset_queen(int r) {
  while(!addition.empty() && addition.top().first == r) {
	chess_map[addition.top().second.first][addition.top().second.second] = false;
	addition.pop();
  }
}

void recursion(int r) {
  if(r == N) {
	res++;
	return;
  }
  for(int c = 0; c < N; c++) {
	if(!chess_map[r][c]) {
	  add_queen(r, c);
	  recursion(r+1);
	  reset_queen(r);
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  res = 0;
  for(int i = 0; i < 15; i++) {
	memset(chess_map[i], false, 15*sizeof(bool));
  }
  recursion(0);
  
  cout << res << "\n";
  cout << "\n";
  return 0;
}
