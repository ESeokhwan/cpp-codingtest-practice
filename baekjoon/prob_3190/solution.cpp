#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int board[100][100];
int moving[10500];

pair<int, int> dirs[4] = { 
  { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(board, -1, sizeof(board));
  memset(moving, 0, sizeof(moving));
  
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
	int r, c;
	cin >> r >> c;
	board[r - 1][c - 1] = -2;
  }

  cin >> l;
  for (int i = 0; i < l; i++) {
	int t;
	char p;
	cin >> t >> p;
	if (p == 'L') moving[t] = -1;
	if (p == 'D') moving[t] = 1;
  }

  int head_r = 0;
  int head_c = 0;
  int tail_r = 0;
  int tail_c = 0;
  board[0][0] = 0;

  int cnt;
  for (cnt = 1; cnt <= 10500; cnt++) {
	int eat_apple = 0;
	int new_head_r = head_r + dirs[board[head_r][head_c]].first;
	int new_head_c = head_c + dirs[board[head_r][head_c]].second;
	if (new_head_r < 0 || new_head_r >= n || new_head_c < 0 || new_head_c >= n) break;
	if (board[new_head_r][new_head_c] >= 0) break;
	if (board[new_head_r][new_head_c] == -2) eat_apple = 1;
	board[new_head_r][new_head_c] = ((board[head_r][head_c] + moving[cnt] + 4) % 4);
	head_r = new_head_r;
	head_c = new_head_c;
	
	if (eat_apple != 1) {
	  int new_tail_r = tail_r + dirs[board[tail_r][tail_c]].first;
	  int new_tail_c = tail_c + dirs[board[tail_r][tail_c]].second;
	  board[tail_r][tail_c] = -1;
	  tail_r = new_tail_r;
	  tail_c = new_tail_c;
	}
  }

  cout << cnt << "\n";
  return 0;
}

