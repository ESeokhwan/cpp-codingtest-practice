#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[100000][5];
int init_nums[1024][1024];

int bt[1024][1024];
int bt_r[1024][1024];

int get_sum(int r, int c) {
  if(r < 0 || c < 0) return 0;
  int res = 0;
  int i = r + 1;
  while(i >= 1) {
	int j = c + 1;
	while(j >= 1) {
	  res += bt[i - 1][j - 1];
	  j -= j&(-j);
	}
	i -= i&(-i);
  }
  return res;
}

int get_sum(int r1, int c1, int r2, int c2) {
  return get_sum(r2, c2) - (get_sum(r2, c1 - 1) + get_sum(r1 - 1, c2)) + get_sum(r1 - 1, c1 - 1);
}

void update(int r, int c, int new_val) {
  int old_val = get_sum(r, c, r, c);
  int offset = new_val - old_val;

  int i = r + 1;
  while(i <= n) {
	int j = c + 1;
	while(j <= n) {
	  bt[i - 1][j - 1] += offset;
	  j += j&(-j);
	}
	i += i&(-i);
  }
}

void set_bt() {
  memset(bt, 0, sizeof(bt));
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) update(i, j, init_nums[i][j]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  cin >> init_nums[i][j];
	}
  }
  for(int i = 0; i < m; i++) {
	cin >> input[i][0];
	if(input[i][0] == 0) cin >> input[i][1] >> input[i][2] >> input[i][3];
	if(input[i][0] == 1) cin >> input[i][1] >> input[i][2] >> input[i][3] >> input[i][4];
  }

  set_bt();

  for(int i = 0; i < m; i++) {
	if(input[i][0] == 0) update(input[i][1] - 1, input[i][2] - 1, input[i][3]);
	if(input[i][0] == 1) cout << get_sum(input[i][1] - 1, input[i][2] - 1, input[i][3] - 1, input[i][4] - 1) << "\n";
  }
  cout << "\n";
  return 0;
}
