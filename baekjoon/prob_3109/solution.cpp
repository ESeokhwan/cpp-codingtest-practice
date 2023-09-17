#include <bits/stdc++.h>
using namespace std;

int r, c;
char _map[10000][500];

bool find_route;

int move(int cur_r, int cur_c) {
  if(find_route) return r;
  
  _map[cur_r][cur_c] = 'X';
  if(cur_c == c - 1) {
	find_route = true;
	return cur_r;
  }

  if(cur_r != 0 && _map[cur_r - 1][cur_c + 1] == '.') {
	int sub_res = move(cur_r - 1, cur_c + 1);
	if(sub_res < r) return sub_res;
  }

  if(_map[cur_r][cur_c + 1] == '.') {
	int sub_res = move(cur_r, cur_c + 1);
	if(sub_res < r) return sub_res;
  }
  
  if(cur_r != r - 1 && _map[cur_r + 1][cur_c + 1] == '.') {
	int sub_res = move(cur_r + 1, cur_c + 1);
	if(sub_res < r) return sub_res;
  }
  
  return r;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> r >> c;
  for(int i = 0; i < r; i++) {
	for(int j = 0; j < c; j++) {
	  cin >> _map[i][j];
	}
  }

  int res = 0;
  for(int i = 0; i < r; i++) {
	find_route = false;
	if(move(i, 0) < r) {
	  res += 1;
	}
  }
  cout << res << "\n";
  return 0;
}
