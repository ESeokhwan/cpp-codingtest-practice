#include <bits/stdc++.h>
using namespace std;

int r1, r2, c1, c2;
int _map[52][52];

int get_num_len(int num) {
  int res = 0;
  while(num != 0) {
	res += 1;
	num = num / 10;
  }

  return res;
}


string num_with_padding(int num, int len) {
  int num_len = get_num_len(num);

  string res = "";
  for(int i = 0; i < len - num_len; i++) {
	res += " ";
  }
  res += to_string(num);
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> r1 >> c1 >> r2 >> c2;

  int cnt = 1;
  int cur_r = -1 * r1;
  int cur_c = -1 * c1;
  if(cur_r >= 0 && cur_r <= r2 - r1 && cur_c >= 0 && cur_c <= c2 - c1) {
	_map[cur_r][cur_c] = cnt;
  }
  cnt += 1;
  pair<int, int> dirs[2];
  for(int i = 1; i <= 10001; i++) {
	if(i % 2 == 0) {
	  dirs[0] = make_pair(0, -1);
	  dirs[1] = make_pair(1, 0);
	} else {
	  dirs[0] = make_pair(0, 1);
	  dirs[1] = make_pair(-1, 0);
	}
	for(auto dir : dirs) {
	  for(int j = 0; j < i; j++) {
		cur_r += dir.first;
		cur_c += dir.second;
		if(cur_r >= 0 && cur_r <= r2 - r1 && cur_c >= 0 && cur_c <= c2 - c1) {
		  _map[cur_r][cur_c] = cnt;
		}
		cnt += 1;
		if(cnt > 10001 * 10001) break;
	  }
	  if(i == 10001) break;
	}
  }

  int max_num = 0;
  for(int i = 0; i <= r2 - r1; i++) {
	for(int j = 0; j <= c2 - c1; j++) {
	  max_num = max(max_num, _map[i][j]);
	}
  }

  int max_len = get_num_len(max_num);
  for(int i = 0; i <= r2 - r1; i++) {
	for(int j = 0; j <= c2 - c1; j++) {
	  cout << num_with_padding(_map[i][j], max_len) << " ";
	}
	cout << "\n";
  }
  return 0;
}
