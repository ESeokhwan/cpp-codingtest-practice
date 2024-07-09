#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int n1, n2, m1, m2;
char _map1[105][105];
char _map2[105][105];

pair<int, int> mults[4] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

pair<int, int> turn_right(int cnt, int R, int C, int cur_r, int cur_c) {
  if (cnt % 4 == 1) return { cur_c, R - cur_r - 1 };
  if (cnt % 4 == 2) return { R - cur_r - 1, C - cur_c - 1 };
  if (cnt % 4 == 3) return { C - cur_c - 1, cur_r };
  return { cur_r, cur_c };
}

int merge(int sp_r, int sp_c, int turn_cnt) {
  int min_ex_r = 0;
  int min_ex_c = 0;
  int max_ex_r = n1 - 1;
  int max_ex_c = m1 - 1;
  bool failed = false;
  for (int i = 0; i < n2; i++) {
	for (int j = 0; j < m2; j++) {
	  pair<int, int> cp_on_2 = turn_right(turn_cnt, n2, m2, i, j);
	  int cur_r_1 = sp_r + cp_on_2.first;
	  int cur_c_1 = sp_c + cp_on_2.second;
	  int cur_r_2 = i;
	  int cur_c_2 = j;
	  if (cur_r_1 < 0 || cur_r_1 >= n1 || cur_c_1 < 0 || cur_c_1 >= m1) {
		min_ex_r = min(min_ex_r, cur_r_1);
		min_ex_c = min(min_ex_c, cur_c_1);
		max_ex_r = max(max_ex_r, cur_r_1);
		max_ex_c = max(max_ex_c, cur_c_1);
		continue;
	  }
//	  if (sp_r == 0 && sp_c == 0 && turn_cnt == 2) {
//		cout << "1 : " << cur_r_1 << " " << cur_c_1 << " " << _map1[cur_r_1][cur_c_1] << "\n";
//		cout << "2 : " << cur_r_2 << " " << cur_c_2 << " " << _map2[cur_r_2][cur_c_2] << "\n";  	
//	  }

	  if (_map1[cur_r_1][cur_c_1] == '1' && _map2[cur_r_2][cur_c_2] == '1') {
		failed = true;
		break;
	  }
	}
	if (failed) {
	  break;
	}
  }

  if (failed) return 98765432;
  return (1 + max_ex_r - min_ex_r) * (1 + max_ex_c - min_ex_c);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n1 >> m1;
  for (int i = 0; i < n1; i++) {
	for (int j = 0; j < m1; j++) {
	  cin >> _map1[i][j];
	}
  }
  
  cin >> n2 >> m2;
  for (int i = 0; i < n2; i++) {
	for (int j = 0; j < m2; j++) {
	  cin >> _map2[i][j];
	}
  }

  int res = 100 * 100;
  for (int i = 0; i < max(n1, m1) + 3; i++) {
	for (int j = 0; j < max(n1, m1) + 3; j++) {
	  for (int k = 0; k < 4; k++) {
		for (auto mult: mults) {
		  int st_r = i * mult.first;
		  int st_c = j * mult.second;
		  int tmp_res = merge(st_r, st_c, k);
//		  cout << st_r << " " << st_c << " " << k << " " << tmp_res << "\n";
		  res = min(res, tmp_res);
		}
	  }
	}
  }

  cout << res << "\n";
  return 0;
}
