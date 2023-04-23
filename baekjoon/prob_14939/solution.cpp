#include <bits/stdc++.h>
using namespace std;

bool _map[10][10];
long long res1;

void s_on(int r, int c) {
  _map[r][c] = !_map[r][c];
  if(r - 1 >= 0) _map[r-1][c] = !_map[r-1][c];
  if(r + 1 < 10) _map[r+1][c] = !_map[r+1][c];
  if(c - 1 >= 0) _map[r][c-1] = !_map[r][c-1];
  if(c + 1 < 10) _map[r][c+1] = !_map[r][c+1];
}

void dfs(long long cnt, int r, int c) {
  if(r == 9 && c == 10) {
	if(!_map[9][9]) {
	  if(res1 != -1) res1 = min(res1, cnt);
	  else res1 = cnt;
	}
	return;
  }

  int nr, nc;
  if(c < 9 - r) {
	if(r == 0) {
	  nr = c + 1;
	  nc = 0;
	} else {
	  nr = r - 1;
	  nc = c + 1;
	}
  } else {
	if(c == 9) {
	  nc = r + 1;
	  nr = 9;
	} else {
	  nr = r - 1;
	  nc = c + 1;
	}
  }
  
  if(!(c - 1 >= 0 && _map[r][c-1])) {
	if(!(c == 9 && r - 1 >= 0 && _map[r-1][c])) dfs(cnt, nr, nc);
  }
  
  s_on(r, c);
  if(!(c - 1 >= 0 && _map[r][c-1])) {
	if(!(c == 9 && r - 1 >= 0 && _map[r-1][c])) dfs(cnt + 1, nr, nc);
  }
  s_on(r, c);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string input;
  for(int i = 0; i < 10; i++) {
	cin >> input;
	for(int j = 0; j < 10; j++) {
	  if(input[j] == '#') _map[i][j] = false;
	  else _map[i][j] = true;
	}
  }

  res1 = -1;
  dfs(0, 0, 0);
  cout <<  res1 << "\n";
  return 0;
}
