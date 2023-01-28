#include <bits/stdc++.h>

using namespace std;

int N;


int max_block;
int table[6][20][20];

int move_mode[4][2] = {
  { 0, 1 }, // horizontal, start from zero, move right
  { 0,-1 }, // horizontal, start from last, move left
  { 1, 1 }, // vertical, start from zero, move down
  { 1,-1 }  // vertical, start from last, move top
};

void move(int cnt, int mode[]) {
  int last_num = 0;
  queue< int > after_move;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  table[cnt+1][i][j] = 0;
	}
  }

  int bound;
  int sp;
  int offset;
  if(mode[1] == 1) {
	sp = 0;
	bound = N;
	offset = 1;
  } else {
	sp = N-1;
	bound = -1;
	offset = -1;
  }
  for(int i = 0; i < N; i++) {
	last_num = 0;
	for(int j = sp; j != bound; j += offset) {
	  int r, c, cp;
	  if(mode[0] == 0) {
		r = i; c = j; 
	  } else {
		r = j; c = i;
	  }
	  cp = table[cnt][r][c];
	  
	  if(last_num == 0) {
		last_num = cp;
	  } else if(last_num == cp) {
		after_move.push(2*cp);
		last_num = 0;
	  } else if(cp != 0) {
		after_move.push(last_num);
		last_num = cp;
	  }
	}
	if(last_num != 0) after_move.push(last_num);
	for(int j = sp; !after_move.empty(); j += offset) {
	  if(mode[0] == 0) table[cnt+1][i][j] = after_move.front();
	  else table[cnt+1][j][i] = after_move.front();
	  after_move.pop();
	}
  }
}

int getMax(int cnt) {
  int local_max = 0;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  if(local_max < table[cnt][i][j]) local_max = table[cnt][i][j];
	}
  }
  return local_max;
}

void rec(int acc, int cnt) {
  if(cnt == 5) {
	max_block = max(max_block, max(acc, getMax(cnt)));
	return;
  }

  for(int i = 0; i < 4; i++) {
	move(cnt, move_mode[i]);
	rec(max(acc, getMax(cnt)), cnt+1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for(int i = 0; i < N; i++) {
	for(int j = 0; j < N; j++) {
	  cin >> table[0][i][j];
	}
  }

  rec(0, 0);
  cout << max_block << "\n";
  cout << "\n";
  return 0;
}

