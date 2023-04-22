#include <bits/stdc++.h>
using namespace std;

int n;
int input[10000][3];
int res;

int block[6][2][2] = 
{
  {
	{ 1, 0 },
	{ 0, 0 }
  }, 
  {
	{ 1, 1 },
	{ 0, 0 }
  }, 
  {
	{ 1, 0 },
	{ 1, 0 }
  }, 
  {
	{ 1, 0 },
	{ 0, 0 }
  },
  {
	{ 1, 0 },
	{ 1, 0 }
  },
  {
	{ 1, 1 },
	{ 0, 0 }
  }
};

bool _map[2][7][5];

void move(int t, int r, int c, bool a) {
  int map_n = 0;
  if(a == true) {
	map_n = 1;
	c = r;
	t += 3;
  }
  r = 0;

  bool flag = false;
  while(!flag) {
	int nr = r + 1;
	for(int i = 1; i >= 0; i--) {
	  for(int j = 0; j < 2; j++) {
		int tmp_r = nr + i;
		int tmp_c = c + j;
		if(block[t][i][j] && (tmp_r > 5 || _map[map_n][tmp_r][tmp_c])){
		  for(int k = 0; k < 2; k++) {
			for(int l = 0; l < 2; l++) _map[map_n][r + k][c + l] |= block[t][k][l];
		  }
		  flag = true;
		}
	  }
	}
	r += 1;
  }
}

void remove_fill() {
  for(int a = 0; a < 2; a++) {
	for(int i = 0; i < 6; i++) {
	  bool is_fill = true;
	  for(int j = 0; j < 4; j++) is_fill &= _map[a][i][j];
	  if(!is_fill) continue;
	  for(int j = i; j >= 1; j--) {
		for(int k = 0; k < 4; k++) _map[a][j][k] = _map[a][j-1][k];
	  }
	  for(int j = 0; j < 4; j++) _map[a][0][j] = false;
	  res += 1;
	}
  }
}

void remove_over_flow() {
  for(int a = 0; a < 2; a++) {
	for(int i = 0; i < 2; i++) {
	  bool of_flag = false;
	  for(int j = 0; j < 2; j++) {
		for(int k = 0; k < 4; k++) of_flag |= _map[a][j][k];
	  }
	  if(!of_flag) continue;
	
	  for(int j = 5; j >= 1; j--) {
		for(int k = 0; k < 4; k++) _map[a][j][k] = _map[a][j-1][k];
	  }
	  for(int j = 0; j < 4; j++) _map[a][0][j] = false;
	}
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(_map, false, sizeof(_map));
  cin >> n;
  for(int i = 0; i < n; i++) cin >> input[i][0] >> input[i][1] >> input[i][2];

  res = 0;
  for(int i = 0; i < n; i++) {
	move(input[i][0] - 1, input[i][1], input[i][2], true);
	move(input[i][0] - 1, input[i][1], input[i][2], false);
	remove_fill();
	remove_over_flow();
  }

  cout << res << "\n";

  res = 0;
  for(int i = 0; i < 6; i++) {
	for(int j = 0; j < 4; j++) {
	  if(_map[0][i][j]) res++;
	  if(_map[1][i][j]) res++;
	}
  }
  cout << res << "\n";
  return 0;
}

