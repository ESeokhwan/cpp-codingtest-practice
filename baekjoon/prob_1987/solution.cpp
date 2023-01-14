#include <bits/stdc++.h>

using namespace std;

int R, C;
char a_map[20][20];

int max_cnt;

pair< int, int > offset_list[4] = {
  make_pair(1,0),
  make_pair(0,1),
  make_pair(-1,0),
  make_pair(0,-1)
};

void recursion(int acc, pair< int, int > cur_pos, bitset<26> checked) {
  for(pair< int, int > offset : offset_list) {
	int next_r = cur_pos.first + offset.first;
	int next_c = cur_pos.second + offset.second;
	if(next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) {
	  if(max_cnt < acc) max_cnt = acc;
	  continue;
	}
	if(checked.test((int) (a_map[next_r][next_c] - 'A'))) {
	  if(max_cnt < acc) max_cnt = acc;
	  continue;
	}

	bitset<26> new_checked = checked;
	new_checked.set((int) a_map[next_r][next_c] - 'A');
	recursion(acc + 1, make_pair(next_r, next_c), new_checked);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;
  for(int i = 0; i < R; i++) 
	for(int j = 0; j < C; j++)
	  cin >> a_map[i][j];

  max_cnt = 0;

  pair<int, int> init_pos = make_pair(0,0);
  bitset<26> init_checked;
  init_checked.set((int) (a_map[0][0] - 'A'));

  recursion(1, init_pos, init_checked);

  cout << max_cnt << "\n";
  cout << "\n";
  return 0;
}
