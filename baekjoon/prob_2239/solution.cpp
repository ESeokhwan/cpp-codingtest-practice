#include <bits/stdc++.h>
using namespace std;

bool is_end;
int sudoku[9][9];
bool row_check[9][9];
bool col_check[9][9];
bool sq_check[9][9];

bool dup_check(int r, int c, int val) {
  return row_check[r][val-1] 
	|| col_check[c][val-1] || sq_check[(r / 3) * 3 + (c / 3)][val-1];
}

void set_check(int r, int c, int val) {
  sudoku[r][c] = val;
  row_check[r][val-1] = true;
  col_check[c][val-1] = true;
  sq_check[((r / 3) * 3 + (c / 3))][val-1] = true;
}

void reset_check(int r, int c, int val) {
  sudoku[r][c] = 0;
  row_check[r][val-1] = false;
  col_check[c][val-1] = false;
  sq_check[((r / 3) * 3 + (c / 3))][val-1] = false;
}

void dfs(int r, int c) {
  if(is_end) return;

  if(c == 9) {
	r += 1;
	c = 0;
  }
  
  if(r == 9) {
	is_end = true;
	for(int i = 0; i < 9; i++) {
	  for(int j = 0; j < 9; j++) cout << sudoku[i][j];
	  cout << "\n";
	}
	return;
  }

  if(sudoku[r][c] != 0) {
	dfs(r, c+1);
	return;
  }

  for(int i = 1; i <= 9; i++) {
	if(dup_check(r, c, i)) continue;
	set_check(r, c, i);
	dfs(r, c + 1);
	reset_check(r, c, i);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i = 0; i < 9; i++) {
	string input;
	cin >> input;
	for(int j = 0; j < 9; j++) {
	  sudoku[i][j] = (input[j] - '0');
	  if(sudoku[i][j] != 0) set_check(i, j, sudoku[i][j]);
	}
  }

  is_end = false;
  dfs(0, 0);
  cout << "\n";
  return 0;
}
