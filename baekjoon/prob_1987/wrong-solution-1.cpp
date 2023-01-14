#include <bits/stdc++.h>

using namespace std;

int R, C;
char a_map[20][20];

vector< bitset<26> > checked_list[2];
vector< pair< int, int > > cur_pos_list[2];

int tick;

pair< int, int > offset_list[4] = {
  make_pair(1,0),
  make_pair(0,1),
  make_pair(-1,0),
  make_pair(0,-1)
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> R >> C;
  for(int i = 0; i < R; i++) 
	for(int j = 0; j < C; j++)
	  cin >> a_map[i][j];

  cur_pos_list[0].push_back(make_pair(0,0));

  bitset<26> init_checked;
  init_checked.set((int) (a_map[0][0] - 'A'));
  checked_list[0].push_back(init_checked);

  for(int i = 0; true; i++) { 
	cur_pos_list[(i+1)%2].clear();
	checked_list[(i+1)%2].clear();
	cout << "size : " << cur_pos_list[i%2].size() << "\n";
	cout << "sizeof : " << cur_pos_list[i%2].capacity() << "\n";
	for(int j = 0; j < cur_pos_list[i%2].size(); j++) {
	  pair< int, int > cur_pos = cur_pos_list[i%2][j];

	  for(pair< int, int > offset : offset_list) {
		bitset<26> checked = checked_list[i%2][j];
		int next_r = cur_pos.first + offset.first;
		int next_c = cur_pos.second + offset.second;

		if(next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
		if(checked.test((int) (a_map[next_r][next_c] - 'A'))) continue;

		checked.set((int) (a_map[next_r][next_c] - 'A'));
		cur_pos_list[(i+1)%2].push_back(make_pair(next_r, next_c));
		checked_list[(i+1)%2].push_back(checked);
	  }	  
	}
	if(cur_pos_list[(i+1)%2].empty()) {
	  tick = i+1;
	  break;
	}
  }

  cout << tick << "\n";
  cout << "\n";
  return 0;
}




